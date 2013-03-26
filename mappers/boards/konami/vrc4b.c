#include "mappers/mapperinc.h"
#include "mappers/chips/c_vrc4.h"

static void reset(int hard)
{
	vrc4_init(KONAMI_VRC4B);
}

MAPPER(B_VRC4B,reset,0,0,vrc4_state);
