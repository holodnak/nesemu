#include "mappers/mapperinc.h"
#include "mappers/chips/c_txc_22211.h"

static void reset_txc_22211a(int hard)
{
	txc_22211_reset(hard,TXC_22211A);
}

static void reset_txc_22211b(int hard)
{
	txc_22211_reset(hard,TXC_22211B);
}

static void reset_txc_22211c(int hard)
{
	txc_22211_reset(hard,TXC_22211C);
}

MAPPER(B_TXC_22211A,reset_txc_22211a,0,0,txc_22211_state);
MAPPER(B_TXC_22211B,reset_txc_22211b,0,0,txc_22211_state);
MAPPER(B_TXC_22211C,reset_txc_22211c,0,0,txc_22211_state);
