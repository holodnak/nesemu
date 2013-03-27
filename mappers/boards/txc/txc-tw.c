#include "mappers/mapperinc.h"

static u8 reg;
static writefunc_t write4;

static void sync()
{
	mem_setprg32(8,(reg >> 4) | reg);
}

static u8 read(u32 addr)
{
	if(addr == 0x5FF0)
		return(0x50);
	return(0);
}

static void write(u32 addr,u8 data)
{
	if(addr < 0x4020) {
		write4(addr,data);
		return;
	}
	log_message("txc-tw:  write to $%04X = $%02X\n",addr,data);
	reg = data;
	sync();
}

static void reset(int hard)
{
	int i;

	for(i=8;i<0x10;i++)
		mem_setwrite(i,write);
	write4 = mem_getwrite(4);
	mem_setwrite(4,write);
	mem_setread(5,read);
	reg = 0;
	sync();
}

static void state(int mode,u8 *data)
{
	STATE_U8(reg);
	sync();
}

MAPPER(B_TXC_TW,reset,0,0,state);
