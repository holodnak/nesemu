#include "mappers/mapperinc.h"
#include "mappers/chips/c_sachen_8259.h"

static void reset(int hard)
{
	sachen_8259_init(SACHEN_8259D);
}

MAPPER(B_SACHEN_8259D,reset,0,0,0);
