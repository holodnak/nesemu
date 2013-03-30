#include "mappers/mapperinc.h"

static u8 reg[8],index;

static void sync()
{
	mem_setchr2(0,(reg[0] & 0x3F) >> 1);
	mem_setchr2(2,(reg[1] & 0x3F) >> 1);
	mem_setchr1(4,reg[2] | 0x40);
	mem_setchr1(5,reg[3] | 0x40);
	mem_setchr1(6,reg[4] | 0x40);
	mem_setchr1(7,reg[5] | 0x40);
	mem_setprg8(0x8,reg[6]);
	mem_setprg8(0xA,reg[7]);
	mem_setprg16(0xC,0xFF);
}

static void write(u32 addr,u8 data)
{
	switch(addr) {
		case 0x8000:
			index = data;
			break;
		case 0x8001:
			reg[index & 7] = data;
			sync();
			break;
	}
}

static void reset(int hard)
{
	int i;

	for(i=8;i<16;i++)
		mem_setwrite(i,write);
	for(i=0;i<8;i++)
		reg[i] = 0;
	index = 0;
	sync();
}

static void state(int mode,u8 *data)
{
	STATE_U8(index);
	STATE_ARRAY_U8(reg,8);
	sync();
}

MAPPER(B_NAMCOT_3446,reset,0,0,state);
