#include "mappers/mapperinc.h"

static u8 reg;

static void sync()
{
	mem_setprg32(8,(reg >> 4) | reg);
	if(nes->rom->chrsize == 0)
		mem_setvram8(0,0);
	else
		mem_setchr8(0,0);
}

static u8 read(u32 addr)
{
	if(addr == 0x5FF0)
		return(0x50);
	return(0);
}

static void write(u32 addr,u8 data)
{
	log_message("txc-mxmdhtwo:  write to $%04X = $%02X\n",addr,data);
	reg = data;
	sync();
}

static void reset(int hard)
{
	int i;

	for(i=8;i<0x10;i++)
		mem_setwrite(i,write);
	mem_setread(5,read);
	nes_setsramsize(2);
	mem_setsram8(6,0);
	reg = 0;
	sync();
}

static void state(int mode,u8 *data)
{
	STATE_U8(reg);
	sync();
}

MAPPER(B_TXC_MXMDHTWO,reset,0,0,state);
