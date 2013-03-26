#include "mappers/mapperinc.h"
#include "mappers/chips/sachen_8259.h"

static void reset(int hard)
{
	sachen_8259_init(SACHEN_8259C);
}

MAPPER(B_SACHEN_8259C,reset,0,0,0);
