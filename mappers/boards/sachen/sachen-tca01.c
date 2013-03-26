#include "mappers/mapperinc.h"

static readfunc_t read4;

static u8 read(u32 addr)
{
	if(addr < 0x4020)
		return(read4(addr));
	if(addr & 0x100)
		return((~addr & 0x3F) | (nes->cpu.x & 0xC0));
	return(0xFF);
}

static void reset(int hard)
{
	read4 = mem_getread(4);
	mem_setread(4,read);
	mem_setread(5,read);
	mem_setprg32(8,0);
	mem_setchr8(0,0);
}

MAPPER(B_SACHEN_TCA01,reset,0,0,0);
