#include "mappers/mapperinc.h"
#include "mappers/chips/c_latch.h"

static void sync()
{
	mem_setprg32(8,0);
	mem_setchr8(0,latch_reg >> 7);
}

static void reset(int hard)
{
	latch_init(sync);
}

MAPPER(B_SA_0036,reset,0,0,latch_state);
