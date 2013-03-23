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

#include "../defines.h"

enum boardid_e {
	B_UNKNOWN = 0,
	B_NROM,
	B_SxROM,
	B_UxROM,
	B_CxROM,
	B_TxROM,
};

typedef struct mapper_s {
	int boardid;					//internal board id
	void (*reset)(int);			//mapper reset function
	void (*tile)(u8,int);		//tile read handler
	void (*line)(int,int);		//scanline handler
	void (*state)(int,u8*);		//load/save state information
	} mapper_t;

mapper_t *mapper_init(int board);

u32 get_board_ines(int num);
u32 get_board_ines20(int num,int sub);
u32 get_board_unif(char *board);

#endif
