#include "mappers/mapperinc.h"

static u8 reg;

static void sync()
{
	mem_setprg32(8,reg >> 4);
	mem_setchr8(0,reg & 0xF);
}

static void write(u32 addr,u8 data)
{
	reg = data;
	sync();
}

static void reset(int hard)
{
	int i;

	for(i=8;i<0x10;i++)
		mem_setwrite(i,write);
	reg = 0;
	sync();
}

static void state(int mode,u8 *data)
{
	STATE_U8(reg);
	sync();
}

MAPPER(B_TXC_STRIKEWOLF,reset,0,0,state);
