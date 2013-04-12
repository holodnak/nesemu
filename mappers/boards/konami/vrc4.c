#include "mappers/mapperinc.h"
#include "mappers/chips/c_vrc4.h"

static void reset_vrc4a(int hard)
{
	vrc4_init(KONAMI_VRC4A);
}

static void reset_vrc4b(int hard)
{
	vrc4_init(KONAMI_VRC4B);
}

static void reset_vrc4c(int hard)
{
	vrc4_init(KONAMI_VRC4C);
}

static void reset_vrc4d(int hard)
{
	vrc4_init(KONAMI_VRC4D);
}

static void reset_vrc4e(int hard)
{
	vrc4_init(KONAMI_VRC4E);
}

MAPPER(B_VRC4A,reset_vrc4a,0,0,vrc4_state);
MAPPER(B_VRC4B,reset_vrc4b,0,0,vrc4_state);
MAPPER(B_VRC4C,reset_vrc4c,0,0,vrc4_state);
MAPPER(B_VRC4D,reset_vrc4d,0,0,vrc4_state);
MAPPER(B_VRC4E,reset_vrc4e,0,0,vrc4_state);
