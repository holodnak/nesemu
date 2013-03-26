#include "mappers/mapperinc.h"
#include "mappers/chips/c_vrc6.h"

static void reset(int hard)
{
	vrc6_init(KONAMI_VRC6A);
}

MAPPER(B_VRC6A,reset,0,0,vrc6_state);
