#include "mappers/mapperinc.h"
#include "mappers/chips/c_mmc5.h"

static void reset(int hard)
{
//	mmc5_init(mmc5_sync);
	mmc5_init(hard);
}

MAPPER(B_ExROM,reset,0,0,mmc5_state);
