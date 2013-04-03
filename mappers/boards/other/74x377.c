#include "mappers/mapperinc.h"
#include "mappers/chips/c_latch.h"

static void sync()
{
	mem_setprg32(8,latch_reg & 0xF);
	mem_setchr8(0,(latch_reg >> 4) & 0xF);
}

static void reset(int hard)
{
	latch_init(sync);
}

MAPPER(B_74x377,reset,0,0,latch_state);
