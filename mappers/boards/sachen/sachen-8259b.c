#include "mappers/mapperinc.h"
#include "mappers/chips/c_sachen_8259.h"

static void reset(int hard)
{
	sachen_8259_init(SACHEN_8259B);
}

MAPPER(B_SACHEN_8259B,reset,0,0,0);
