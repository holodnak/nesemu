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

#include "nes_io.h"
#include "nes.h"
#include "nes/ppu/event.h"
#include "system/input.h"

u8 nes_frameirq;

//read from apu/joypads
u8 nes_read_4000(u32 addr)
{
	//try input port 0 read
	if(addr == 0x4016)
		return(nes->inputdev[0]->read());

	//try input port 1 read
	if(addr == 0x4017)
		return(nes->inputdev[1]->read() | nes->expdev->read());

	if(addr == 0x4015) {
		u8 ret = apu_read(addr) | nes_frameirq;
		nes_frameirq = 0;
		return(ret);
	}

	//else return an apu read
	return(apu_read(addr));
}

u8 nes_frame_irqmode = 0;

//write to sprite dma, nes joypad strobe, and apu registers
void nes_write_4000(u32 addr,u8 data)
{
	u32 temp,temp2,i;

	//write to apu
	if(addr <= 0x4013 || addr == 0x4015) {
		nes->apuregs[addr & 0x1F] = data;
		apu_write(addr,data);
	}

	//sprite dma write
	else if(addr == 0x4014) {
		temp = nes->ppu.spraddr;
		temp2 = data << 8;
		for (i = 0; i < 256; i++) {
			nes->sprmem[temp] = dead6502_read(temp2);
			temp = (temp + 1) & 0xFF;
			temp2++;
		}
		nes_burn(2 * 256);
	}

	//strobe joypads
	else if(addr == 0x4016) {
		if(nes->inputdev[0]->write)	nes->inputdev[0]->write(data);
		if(nes->inputdev[1]->write)	nes->inputdev[1]->write(data);
		if(nes->expdev->write)			nes->expdev->write(data);
		if(((data & 1) == 0) && (nes->strobe & 1)) {
			if(nes->inputdev[0]->strobe)	nes->inputdev[0]->strobe();
			if(nes->inputdev[1]->strobe)	nes->inputdev[1]->strobe();
			if(nes->expdev->strobe)			nes->expdev->strobe();
		}
		nes->strobe = data;
	}

	//frame irq control
	else if(addr == 0x4017) {
		nes->frame_irqmode = data;
		nes_frame_irqmode = data;
	}
}

u8 nes_read_mem(u32 addr)
{
	if(nes->cpu.readpages[addr >> 12])
		return(nes->cpu.readpages[addr >> 12][addr & 0xFFF]);
	return(0);
}

void nes_write_mem(u32 addr,u8 data)
{
	if(nes->cpu.writepages[addr >> 12])
		nes->cpu.writepages[addr >> 12][addr & 0xFFF] = data;
}

//read nes rom memory area ($8000-FFFF)
u8 nes_read_rom(u32 addr)
{
	return(nes->cpu.readpages[addr >> 12][addr & 0xFFF]);
}
