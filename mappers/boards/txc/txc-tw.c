#include "mappers/mapperinc.h"
#include "mappers/chips/c_mmc3.h"

static u8 reg;
static writefunc_t write4;

static void sync()
{
	mem_setprg32(8,reg & 3);
	mmc3_syncchr(0xFF,0);
	mmc3_syncmirror();
	mmc3_syncsram();
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
	reg = data | (data >> 4);
	sync();
}

static void reset(int hard)
{
	write4 = mem_getwrite(4);
	mem_setread(5,read);
	mem_setwrite(4,write);
	reg = 0;
	mmc3_init(sync);
}

static void state(int mode,u8 *data)
{
	STATE_U8(reg);
	mmc3_state(mode,data);
	sync();
}

MAPPER(B_TXC_TW,reset,0,mmc3_line,state);
