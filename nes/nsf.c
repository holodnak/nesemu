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

#include <string.h>
#include "nes/nes.h"
#include "mappers/mapper.h"

#define BIOS_IDLE		0x00
#define BIOS_INIT		0x01
#define BIOS_PLAY		0x02

extern u8 nsfbios_rom[];

static u8 prg[8],song;
static u8 disabled,bios_cmd;
static writefunc_t write4;

static u8 read_bios(u32 addr);

static void sync()
{
	int i;

	//sync nsf prg banks
	for(i=8;i<0xF;i++)
		mem_setprg4(i,prg[i & 7]);

	//klugde
	mem_setprg4(1,prg[7]);
}

static u8 read_bios(u32 addr)
{
	u8 ret;

	//bios registers
	if(addr < 0x3100) {
		if(addr < 0x3004 && addr >= 0x3000)
			log_message("bios reading regs at $%04X\n",addr);
		log_message("loadaddr = $%04X\n",nes->rom->nsf.loadaddr);
		log_message("initaddr = $%04X\n",nes->rom->nsf.initaddr);
		log_message("playaddr = $%04X\n",nes->rom->nsf.playaddr);
		switch(addr & 0xFF) {
			case 0: return(nes->rom->nsf.initaddr & 0xFF);
			case 1: return(nes->rom->nsf.initaddr >> 8);
			case 2: return(nes->rom->nsf.playaddr & 0xFF);
			case 3: return(nes->rom->nsf.playaddr >> 8);
			case 4: ret = bios_cmd; bios_cmd = 0; return(ret);
			case 5: return(0);
			case 0x10: return(song);
		}
		log_message("bios reading regs at $%04X\n",addr);
		return(0);
	}
	return(nsfbios_rom[addr & 0xFFF]);
}

static void write_bios(u32 addr,u8 data)
{
	if(addr < 0x3100) {
		switch(addr & 0xFF) {
			case 4:
				bios_cmd = data;
				break;
			case 0x10:
				song = data;
				log_message("writing song reg = $%02X\n",song);
				break;
			case 0x11:
			case 0x12:
			case 0x13:
			case 0x14:
				log_message("writing reg $%02X = $%02X\n",addr & 0xFF,song);
				break;
		}
	}
}

static u8 read_vectors(u32 addr)
{
	if(addr >= 0xFFFA) {
//		log_message("reading vector at $%04X\n",addr);
		return(nsfbios_rom[addr & 0xFFF]);
	}
	return(mem_getreadptr(1)[addr & 0xFFF]);
}

static void write(u32 addr,u8 data)
{
	if(addr < 0x4020) {
		write4(addr,data);
		return;
	}
	switch(addr) {
		case 0x5FF0:
			if(disabled == 0) {
				switch(data) {

				}
			}
		case 0x5FF8: prg[0] = data; sync(); break;
		case 0x5FF9: prg[1] = data; sync(); break;
		case 0x5FFA: prg[2] = data; sync(); break;
		case 0x5FFB: prg[3] = data; sync(); break;
		case 0x5FFC: prg[4] = data; sync(); break;
		case 0x5FFD: prg[5] = data; sync(); break;
		case 0x5FFE: prg[6] = data; sync(); break;
		case 0x5FFF: prg[7] = data; sync(); break;
	}
}

void nsf_line(int line,int pcycles)
{
	if(line == 20) {
//		bios_cmd = BIOS_INIT;
//		dead6502_irq();
	}
	//call play address
	if(line >= 100 && line <= 108) {
//		log_message("calling bios play\n");
//		bios_cmd = BIOS_PLAY;
//		dead6502_irq();
	}
}

void nsf_init(int hard)
{
	int i;

	disabled = 0;
	nes_setsramsize(2 + 8);
	write4 = mem_getwrite(4);
	mem_setwrite(4,write);
	mem_setwrite(5,write);
	mem_setread(0x3,read_bios);
	mem_setread(0xF,read_vectors);
	mem_setsram8(6,0);
	disabled = 0;
	bios_cmd = 1;
	if(memcmp(nes->rom->nsf.bankswitch,"\0\0\0\0\0\0\0\0",8) != 0) { //bankswitched
		log_message("setting up nsf bankswitch:\n");
		for(i=0;i<8;i++) {
			log_message("setting bank %d to $%02X\n",8+i,nes->rom->nsf.bankswitch[i]);
			prg[i] = nes->rom->nsf.bankswitch[i];
		}
	}
	//setup bios
	mem_setread(3,read_bios);
	mem_setwrite(3,write_bios);
	mem_setreadptr(0xF,0);
	mem_setwriteptr(0xF,0);
	sync();
}

MAPPER_INES(NSF_MAPPER,nsf_init,0,nsf_line,0);
