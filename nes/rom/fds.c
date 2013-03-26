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
#include "system/config.h"
#include "mappers/mapperid.h"

static u8 fdsident[] = "FDS\x1a";
static u8 fdsident2[] = "\x01*NINTENDO-HVC*";

static void load_fds_header(rom_t *ret,u8 *header)
{
	//set number of disk sides
	ret->disksides = header[4];

	log_message("load_fds_header: %d sides (%dkb)\n",ret->disksides,ret->disksides * 65500 / 1024);
}

rom_t *rom_load_fds(int fd,rom_t *ret)
{
	u8 header[16];

	//first check if the disk system bios rom is loaded
	if(nes->disksys_rom == 0) {
		if(nes->hle_fds_rom == 0) {
			log_error("fds bios not loaded, cannot load fds disk\n");
			return(0);
		}
		config.fdsbios = 1;
		log_message("using hle fds bios\n");
	}
	if(nes->hle_fds_rom == 0) {
		if(nes->disksys_rom == 0) {
			log_error("fds bios not loaded, cannot load fds disk\n");
			return(0);
		}
		config.fdsbios = 0;
		log_message("using nintendo fds bios\n");
	}

	//read header
	file_read(fd,header,16);

	if(memcmp(header,fdsident2,15) == 0) {
		int size;

		file_seek(fd,0,SEEK_END);
		size = file_tell(fd);
		if((size % 65500) != 0) {
			log_message("rom_load_fds:  strange disk image size, aborting\n");
			return(0);
		}
		ret->disksides = size / 65500;
		file_seek(fd,0,SEEK_SET);
	}
	else if(memcmp(header,fdsident,4) == 0) {
		load_fds_header(ret,header);
	}

	//set mapper assigned to fds system
	ret->boardid = (config.fdsbios == 0) ? B_FDS : B_HLEFDS;

	//allocate memory for disk data
	ret->diskdata = (u8*)malloc(ret->disksides * 65500);
	ret->orig_diskdata = (u8*)malloc(ret->disksides * 65500);

	//try to read fds disk data
	if(file_read(fd,ret->diskdata,ret->disksides * 65500) != (ret->disksides * 65500)) {
		log_error("reading all of disk data\n");
		return(0);
	}

	//copy the data read to seperate buffer (used for saving disk changes)
	memcpy(ret->orig_diskdata,ret->diskdata,ret->disksides * 65500);

	log_message("rom_load_fds:  loaded disk, %d sides\n",ret->disksides);
	return(ret);
}
