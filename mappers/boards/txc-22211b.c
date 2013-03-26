#include "mappers/mapperinc.h"
#include "mappers/chips/c_txc_22211.h"

static void reset(int hard)
{
	txc_22211_reset(hard,TXC_22211B);
}

MAPPER(B_TXC_22211B,reset,0,0,0);
