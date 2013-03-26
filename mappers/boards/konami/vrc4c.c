#include "mappers/mapperinc.h"
#include "mappers/chips/c_vrc4.h"

static void reset(int hard)
{
	vrc4_init(KONAMI_VRC4C);
}

MAPPER(B_VRC4C,reset,0,0,vrc4_state);
