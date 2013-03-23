#include "mapperinc.h"

#undef MAPPER
#define MAPPER(n) \
	{ \
	extern mapper_t mapper##n; \
	if(board == n) return(&mapper##n); \
	}

mapper_t *mapper_init(int board)
{
	//boards
	MAPPER(B_NROM);			MAPPER(B_SxROM);			MAPPER(B_UxROM);			MAPPER(B_CxROM);
	MAPPER(B_TxROM);			MAPPER(B_PxROM);

	MAPPER(B_SACHEN_74LS374);

	//extras
	MAPPER(B_NSF);
	MAPPER(B_FDS);
	MAPPER(B_HLEFDS);

	return(0);
}
