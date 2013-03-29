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
#include "mappers/mapperid.h"

static int load_ines_header(rom_t *ret,u8 *header)
{
	int mapper;

	ret->prgsize = header[4] * 0x4000;
	ret->chrsize = header[5] * 0x2000;
	ret->prgmask = rom_createmask(ret->prgsize);
	ret->chrmask = rom_createmask(ret->chrsize);
	ret->vrammask = rom_createmask(0);				//start with no vram, let mapper control this
	mapper = (header[6] & 0xF0) >> 4;
	if(memcmp(&header[8],"\0\0\0\0\0\0\0\0",8) != 0)
		log_message("load_ines_header:  dirty header! (%c%c%c%c%c%c%c%c%c)\n",header[7],header[8],header[9],header[10],header[11],header[12],header[13],header[14],header[15]);
	else
		mapper |= header[7] & 0xF0;
	if(ret->mirroring & 4)
		ret->mirroring = 4;
	else
		ret->mirroring = header[6] & 1;
	if(header[6] & 2)
		rom_setsramsize(ret,2);
	if(header[7] & 2)
		ret->pc10romsize = KB(8);
	log_message("load_ines_header:  %dkb prg, %dkb chr, mapper %d, %s mirroring\n",
		ret->prgsize / 1024,ret->chrsize / 1024,mapper,
		(ret->mirroring == 4) ? "four screen" :
		((ret->mirroring == 0) ? "horizontal" : "vertical"));

	ret->boardid = get_ines_boardid(mapper);
	if(ret->boardid == B_UNSUPPORTED) {
		log_message("load_ines_header:  ines mapper %d unsupported\n",mapper);
		return(1);
	}
	return(0);
}

rom_t *rom_load_ines(int fd,rom_t *ret)
{
	u8 header[16];

	//read header (again...)
	file_read(fd,header,16);

	//load ines 2.0 header
	if(load_ines_header(ret,header) != 0) {
		return(0);
	}

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

	if(ret->pc10romsize) {

		//allocate memory for pc10 rom
		ret->pc10rom = (u8*)malloc(ret->pc10romsize);

		//read in the chr rom data
		if(file_read(fd,ret->pc10rom,ret->pc10romsize) != ret->pc10romsize) {
			log_message("rom_load: error reading pc10 rom data\n");
			rom_unload(ret);
			return(0);
		}
	}

	//look for rom in database and update its mapper info
/*	if(rom_checkdb(ret,0) == -1) {
		return(0);
	}*/
	if(rom_checkdb(ret,0) == 0) {
		int fd;
		char str[512];
#ifdef WIN32
	#define CRCFILE "c:\\mingw\\new_crcs.c"
#else
	#define CRCFILE "NEW_CRCS.C"
#endif
#define getboardname(n) "?"
		if((fd = file_open(CRCFILE,"uat")) >= 0) {
			sprintf(str,"\t{\"%s\",0x%08X,0x%08X,\"%s\",%s},\n",ret->filename,rom_prgcrc32(ret),rom_chrcrc32(ret),getboardname(ret),((ret->chrsize == 0) ? "ROM_NOCHR" : "0"));
			file_write(fd,str,strlen(str));
			file_close(fd);
		}
	}

	return(ret);
}
