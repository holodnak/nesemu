/***************************************************************************
 *   Copyright (C) 2006-2009 by Dead_Body   *
 *   jamesholodnak@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defines.h"
#include "nes/nes.h"
#include "system/file.h"

static void load_ines_header(rom_t *ret,u8 *header)
{
	ret->prgsize = header[4] * 0x4000;
	ret->chrsize = header[5] * 0x2000;
	ret->prgmask = rom_createmask(ret->prgsize);
	ret->chrmask = rom_createmask(ret->chrsize);
	ret->vrammask = rom_createmask(0);				//start with no vram, let mapper control this
	ret->mapper = (header[6] & 0xF0) >> 4;
	if(memcmp(&header[8],"\0\0\0\0\0\0\0\0",8) != 0)
		log_message("load_ines_header:  dirty header! (%c%c%c%c%c%c%c%c%c)\n",header[7],header[8],header[9],header[10],header[11],header[12],header[13],header[14],header[15]);
	else
		ret->mapper |= header[7] & 0xF0;
	if(ret->mirroring & 4)
		ret->mirroring = 4;
	else
		ret->mirroring = header[6] & 1;
	if(header[6] & 2)
		rom_setsramsize(ret,2);
	log_message("load_ines_header:  %dkb prg, %dkb chr, mapper %d, %s mirroring\n",
		ret->prgsize / 1024,ret->chrsize / 1024,ret->mapper,
		(ret->mirroring == 4) ? "four screen" :
		((ret->mirroring == 0) ? "horizontal" : "vertical"));
}

static char *getboardname(rom_t *rom)
{
	static char ret[32];

	strcpy(ret,"?");
	switch(rom->mapper) {
		case 0:
			if(rom->chrsize) {
				if(rom->prgsize == KB(16))
					strcpy(ret,"NES-NROM-128");
				else
					strcpy(ret,"NES-NROM-256");
			}
			else
				log_error("mapper 0: rom must have chr rom\n");
		case 2:
			if(rom->prgsize == KB(128))
				strcpy(ret,"NES-UNROM");
			else
				strcpy(ret,"NES-UOROM");
			break;
		case 3: strcpy(ret,"NES-CNROM"); break;
		case 4:
			if(rom->mirroring & 4) {
				if(rom->prgsize == KB(64))
					strcpy(ret,"NES-TVROM");
				else if(rom->prgsize >= KB(128) && rom->prgsize <= KB(512))
					strcpy(ret,"NES-TR1ROM");
				else {
					strcpy(ret,"NES-TR1ROM");
					log_warning("mapper 4: bad prg size, defaulting to TR1ROM\n");
				}
			}
			else {
				if(rom->prgsize == KB(32))
					strcpy(ret,"NES-TEROM");
				if(rom->prgsize == KB(64))
					strcpy(ret,"NES-TBROM");
				else if(rom->prgsize >= KB(128) && rom->prgsize <= KB(512)) {
					if(rom->chrsize == 0) {
						if(rom->sramsize == 0)
							strcpy(ret,"NES-TGROM");
						else
							strcpy(ret,"NES-TNROM");
					}
					else if(rom->chrsize <= KB(64))
						strcpy(ret,"NES-TFROM");
					else if(rom->chrsize <= KB(256)) {
						if(rom->sramsize == 0)
							strcpy(ret,"NES-TLROM");
						else
							strcpy(ret,"NES-TSROM");
					}
					else {
						strcpy(ret,"NES-TSROM");
						log_error("mapper 7: bad chr size, defaulting to TSROM\n");
					}
				}
				else {
					strcpy(ret,"NES-TSROM");
					log_error("mapper 7: bad prg size, defaulting to TSROM\n");
				}
			}
			break;
		//mapper 6 has no boards (ffe)
		case 7:
			if(rom->chrsize == 0) {
				if(rom->prgsize == KB(256))
					strcpy(ret,"NES-AOROM");
				else if(rom->prgsize == KB(128))
					strcpy(ret,"NES-ANROM");
				else if(rom->prgsize == KB(64))
					strcpy(ret,"NES-AN1ROM");
				else {
					strcpy(ret,"NES-AOROM");
					log_warning("mapper 7: bad prg size, defaulting to AOROM\n");
				}
			}
			else
				log_error("mapper 7: AxROM boards always have chrrom\n");
			break;
		//mapper 8 has no boards (ffe)
		case 9: strcpy(ret,"NES-PNROM"); break;
		case 10:
			if(rom->prgsize == KB(128))
				strcpy(ret,"NES-FJROM"); 
			else
				strcpy(ret,"NES-FKROM"); 
			break;
		case 11: strcpy(ret,"COLORDREAMS-74*377"); break;
	}
	return(ret);
}

rom_t *rom_load_ines(int fd,rom_t *ret)
{
	u8 header[16];

	//read header (again...)
	file_read(fd,header,16);

	//load ines header
	load_ines_header(ret,header);

	//allocate memory for the prg rom
	ret->prg = (u8*)malloc(ret->prgsize);

	//read in the prg rom
	if(file_read(fd,ret->prg,ret->prgsize) != ret->prgsize) {
		log_message("rom_load: error reading prg data\n");
		rom_unload(ret);
		return(0);
	}

	//if chr exists...
	if(ret->chrsize) {

		//allocate memory for chr rom
		ret->chr = (u8*)malloc(ret->chrsize);

		//read in the chr rom data
		if(file_read(fd,ret->chr,ret->chrsize) != ret->chrsize) {
			log_message("rom_load: error reading chr data\n");
			rom_unload(ret);
			return(0);
		}

		//allocate memory for the tile cache
		ret->cache = (cache_t*)malloc(ret->chrsize);
		ret->cache_hflip = (cache_t*)malloc(ret->chrsize);

		//convert all chr tiles to cache tiles
		convert_tiles(ret->chr,ret->cache,ret->chrsize / 16,0);
		convert_tiles(ret->chr,ret->cache_hflip,ret->chrsize / 16,1);
	}

	//if no chr exists, go ahead and set default vram size of 8kb
	else
		rom_setvramsize(ret,1);

	//look for rom in database and update its mapper info
	if(rom_checkdb(ret,0) == 0) {
		int fd;
		char str[512];

		if((fd = file_open("c:\\mingw\\new_crcs.c","uat")) >= 0) {
			sprintf(str,"\t{\"%s\",0x%08X,0x%08X,\"%s\",%s},\n",ret->filename,rom_prgcrc32(ret),rom_chrcrc32(ret),getboardname(ret),((ret->chrsize == 0) ? "ROM_NOCHR" : "0"));
			file_write(fd,str,strlen(str));
			file_close(fd);
		}
	}

	return(ret);
}
