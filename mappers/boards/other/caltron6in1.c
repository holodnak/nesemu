#include "mappers/mapperinc.h"

static u8 reg[2];

static void sync()
{
	mem_setprg32(8,reg[0] & 7);
	mem_setchr8(0,((reg[0] & 0x18) >> 1) | (reg[1] & 3));
	ppu_setmirroring(((~reg[0]) >> 5) & 1);
}

static void write(u32 addr,u8 data)
{
	if(addr < 0x6800)
		reg[0] = addr & 0x3F;
	else if((addr >= 0x8000) && (reg[0] & 4))
		reg[1] = data & 3;
	sync();
}

static void reset(int hard)
{
	int i;

	for(i=6;i<0x10;i++)
		mem_setwrite(i,write);
	reg[0] = reg[1] = 0;
	sync();
}

static void state(int mode,u8 *data)
{
	STATE_ARRAY_U8(reg,2);
	sync();
}

MAPPER(B_CALTRON6IN1,reset,0,0,state);
