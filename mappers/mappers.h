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

#ifndef __mappers_h__
#define __mappers_h__

#include "defines.h"
#include "nes/memory.h"

#define MAPPER(boardid,reset,tile,line,state) \
	mapper_t mapper##boardid = {boardid,reset,tile,line,state}

#define STATE_LOAD		0	//load state info into mapper
#define STATE_SAVE		1	//get state info from mapper
#define STATE_LOADCFG	2	//load config info into mapper
#define STATE_SAVECFG	3	//get config info from mapper

#define CFG_U8(dat)		\
	if(mode == STATE_LOADCFG)	\
		{(dat) = *data++;}	\
	else if(mode == STATE_SAVECFG) \
		{*data++ = (dat);}

#define STATE_U8(dat)		\
	if(mode == STATE_LOAD)	\
		{(dat) = *data++;}	\
	else if(mode == STATE_SAVE) \
		{*data++ = (dat);}

#define STATE_U16(dat)			\
	if(mode == STATE_LOAD) {	\
		(dat) = *data++;			\
		(dat) |= *data++ << 8;	\
	}									\
	else if(mode == STATE_SAVE) {					\
		*data++ = (u8)((dat) & 0xFF);				\
		*data++ = (u8)(((dat) >> 8) & 0xFF);	\
	}

#define STATE_U32(dat)			\
	if(mode == STATE_LOAD) {	\
		(dat) = *data++;			\
		(dat) |= *data++ << 8;	\
		(dat) |= *data++ << 16;	\
		(dat) |= *data++ << 24;	\
	}									\
	else if(mode == STATE_SAVE) {					\
		*data++ = (u8)((dat) & 0xFF);				\
		*data++ = (u8)(((dat) >> 8) & 0xFF);	\
		*data++ = (u8)(((dat) >> 16) & 0xFF);	\
		*data++ = (u8)(((dat) >> 24) & 0xFF);	\
	}

#define STATE_INT(dat)				\
	if(mode == STATE_LOAD) {		\
		u32 _tmpu32;					\
		_tmpu32 = *data++;			\
		_tmpu32 |= *data++ << 8;	\
		_tmpu32 |= *data++ << 16;	\
		_tmpu32 |= *data++ << 24;	\
		dat = (int)_tmpu32;			\
	}										\
	else if(mode == STATE_SAVE) {							\
		*data++ = (u8)((u32)(dat) & 0xFF);				\
		*data++ = (u8)(((u32)(dat) >> 8) & 0xFF);		\
		*data++ = (u8)(((u32)(dat) >> 16) & 0xFF);	\
		*data++ = (u8)(((u32)(dat) >> 24) & 0xFF);	\
	}

#ifdef MEMWATCH
#include "memwatch.h"
#elif defined OSX
#include <memory.h>
#else
#include <malloc.h>
#endif


#define STATE_ARRAY_U8(arr,siz)	\
	{int i; for(i=0;i<(siz);i++)	\
		STATE_U8((arr)[i]); }

typedef struct mapper_s {
	int boardid;					//internal board id
	void (*reset)(int);			//mapper reset function
	void (*tile)(u8,int);		//tile read handler
	void (*line)(int,int);		//scanline handler
	void (*state)(int,u8*);		//load/save state information
} mapper_t;

//converting from ines|ines20|unif to internal board id
int get_ines_boardid(int num);
int get_ines20_boardid(int num,int sub);
int get_unif_boardid(char *board);

//helper for getting supported mapper list
const char *get_unif_board(int idx);

//initialize mapper and get mapper_t struct
mapper_t *mapper_init(int board);

#include "nes/nes.h"

#endif
