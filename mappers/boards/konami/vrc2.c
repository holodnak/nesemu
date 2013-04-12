#include "mappers/mapperinc.h"
#include "mappers/chips/c_vrc2.h"

static void reset_vrc2a(int hard)
{
	vrc2_init(KONAMI_VRC2A);
}

static void reset_vrc2b(int hard)
{
	vrc2_init(KONAMI_VRC2B);
}

MAPPER(B_VRC2A,reset_vrc2a,0,0,vrc2_state);
MAPPER(B_VRC2B,reset_vrc2b,0,0,vrc2_state);
