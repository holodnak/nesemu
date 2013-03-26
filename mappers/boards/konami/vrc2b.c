#include "mappers/mapperinc.h"
#include "mappers/chips/c_vrc2.h"

static void reset(int hard)
{
	vrc2_init(KONAMI_VRC2B);
}

MAPPER(B_VRC2B,reset,0,0,vrc2_state);
