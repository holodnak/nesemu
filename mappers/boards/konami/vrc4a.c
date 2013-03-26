#include "mappers/mapperinc.h"
#include "mappers/chips/c_vrc4.h"

static void reset(int hard)
{
	vrc4_init(KONAMI_VRC4A);
}

MAPPER(B_VRC4A,reset,0,0,vrc4_state);
