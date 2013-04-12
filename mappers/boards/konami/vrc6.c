#include "mappers/mapperinc.h"
#include "mappers/chips/c_vrc6.h"

static void reset_vrc6a(int hard)
{
	vrc6_init(KONAMI_VRC6A);
}

static void reset_vrc6b(int hard)
{
	vrc6_init(KONAMI_VRC6B);
}

MAPPER(B_VRC6A,reset_vrc6a,0,0,vrc6_state);
MAPPER(B_VRC6B,reset_vrc6b,0,0,vrc6_state);
