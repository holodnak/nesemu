#include "mappers/mapper.h"
#include "nes/ppu/ppu.h"

static u8 mode,bank;

static void sync()
{
	if(mode & 1)
		mem_setprg8(0x6,bank | 0x23);
	else
		mem_setprg8(0x6,bank | 0x2F);
	if(mode == 2)
		mem_setprg16(0x8,(bank >> 1) | 1);
	else
		mem_setprg16(0x8,bank >> 1);
	if(mode & 1)
		mem_setprg16(0xC,(bank >> 1) | 1);
	else
		mem_setprg16(0xC,(bank >> 1) | 7);
	ppu_setmirroring((mode == 3) ? MIRROR_H : MIRROR_V);
}

static void write(u32 addr,u8 data)
{
	if(addr < 0x8000)
		mode = ((data >> 3) & 2) | ((data >> 1) & 1);
	else {
		bank = (data & 0xF) << 2;
		if(bank & 4)
			mode = ((data >> 3) & 2) | (mode & 1);
	}
	sync();
}

static void reset(int hard)
{
	int i;

	for(i=6;i<16;i++)
		mem_setwrite(i,write);
	nes_setvramsize(1);
	mem_setvram8(0,0);
	mode = 1;
	bank = 0;
	sync();
}

static void state(int mode,u8 *data)
{
	STATE_U8(mode);
	STATE_U8(bank);
	sync();
}

MAPPER_INES(51,reset,0,0,state);
