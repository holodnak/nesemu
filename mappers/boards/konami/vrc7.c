#include "mappers/mapperinc.h"
#include "mappers/chips/c_vrc7.h"

static void reset_vrc7a(int hard)
{
	vrc7_init(KONAMI_VRC7A);
}

static void reset_vrc7b(int hard)
{
	vrc7_init(KONAMI_VRC7B);
}

MAPPER(B_VRC7A,reset_vrc7a,0,0,vrc7_state);
MAPPER(B_VRC7B,reset_vrc7b,0,0,vrc7_state);
