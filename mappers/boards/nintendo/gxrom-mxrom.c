#include "mappers/mapperinc.h"
#include "mappers/chips/c_latch.h"

static void sync()
{
	mem_setprg32(8,(latch_reg & 0xF0) >> 4);
	if(nes->rom->chrsize)
		mem_setchr8(0,latch_reg & 0xF);
	else
		mem_setvram8(0,0);
}

static void reset(int hard)
{
	latch_init(sync);
}

MAPPER(B_GxROM_MxROM,reset,0,0,latch_state);
