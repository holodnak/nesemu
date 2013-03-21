#include "mappers/mapper.h"
#include "mappers/chips/latch.h"

static void sync()
{
	mem_setprg32(8,0);
	mem_setchr8(0,latch_reg >> 7);
}

static void reset(int hard)
{
	latch_init(sync);
}

MAPPER_UNIF(unl_sa_0036,"UNL-SA-0036",reset,0,0,latch_state,INFO(32 + 4,8,0,2,0,0));
