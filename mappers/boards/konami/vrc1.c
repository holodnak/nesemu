#include "mappers/mapperinc.h"
#include "mappers/chips/c_vrc1.h"

static void reset(int hard)
{
	vrc1_init(hard);
}

MAPPER(B_VRC1,reset,0,0,vrc1_state);
