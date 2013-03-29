#include "mappers/mapperinc.h"
#include "mappers/chips/c_latch.h"

static void sync()
{
	mem_setvram4(0,0);
	mem_setvram4(4,latch_reg & 3);
}

static void reset(int hard)
{
	latch_init(sync);
	mem_setprg32(8,0);
}

MAPPER(B_CPROM,reset,0,0,latch_state);
