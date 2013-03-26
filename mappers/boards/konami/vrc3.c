#include "mappers/mapperinc.h"
#include "mappers/chips/c_vrc3.h"

static void reset(int hard)
{
	vrc3_init(hard);
}

MAPPER(B_VRC3,reset,0,0,vrc3_state);
