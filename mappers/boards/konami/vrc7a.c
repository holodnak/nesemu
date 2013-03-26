#include "mappers/mapperinc.h"
#include "mappers/chips/c_vrc7.h"

static void reset(int hard)
{
	vrc7_init(KONAMI_VRC7A);
}

MAPPER(B_VRC7A,reset,0,0,vrc7_state);
