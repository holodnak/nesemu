#include "mappers/mapperinc.h"
#include "mappers/chips/c_mmc6.h"

static void reset(int hard)
{
	mmc6_init(mmc6_sync);
}

MAPPER(B_HxROM,reset,0,mmc6_line,mmc6_state);
