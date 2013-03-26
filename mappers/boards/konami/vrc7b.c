#include "mappers/mapperinc.h"
#include "mappers/chips/c_vrc7.h"

static void reset(int hard)
{
	vrc7_init(KONAMI_VRC7B);
}

MAPPER(B_VRC7B,reset,0,0,vrc7_state);
