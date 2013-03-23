#include "mapperinc.h"

#undef MAPPER
#define MAPPER(n) \
	{ \
	extern mapper_t mapper##n; \
	if(board == n) return(&mapper##n); \
	}

mapper_t *mapper_init(int board)
{
	MAPPER(B_NROM);		MAPPER(B_SxROM);		MAPPER(B_UxROM);		MAPPER(B_CxROM);
	MAPPER(B_TxROM);		MAPPER(B_PxROM);
	return(0);
}
