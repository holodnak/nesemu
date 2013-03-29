#include "mappers/mapperinc.h"
#include "mappers/chips/c_latch.h"

static void sync()
{
	mem_setprg16(0x8,latch_reg ^ 8);
	mem_setprg16(0xC,0xFF);
	mem_setvram8(0,0);
}

static u8 read6(u32 addr)
{
	return(0);
}

static void reset(int hard)
{
	latch_init(sync);
	mem_setread(6,read6);
}

MAPPER(B_BANDAI_KARAOKE,reset,0,0,latch_state);
