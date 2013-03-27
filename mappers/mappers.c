#include "mapperinc.h"

#undef MAPPER
#define MAPPER(n) \
	{ \
	extern mapper_t mapper##n; \
	if(board == n) return(&mapper##n); \
	}

mapper_t *mapper_init(int board)
{
	//licensed
	//nintendo boards
	MAPPER(B_NROM);			MAPPER(B_SxROM);			MAPPER(B_UxROM);			MAPPER(B_CxROM);
	MAPPER(B_TxROM);			MAPPER(B_PxROM);			MAPPER(B_HxROM);			MAPPER(B_AxROM);

	//unlicensed
	//other boards
	MAPPER(B_CALTRON6IN1);
	MAPPER(B_BIOMIRACLEA);
	MAPPER(B_MARIO1_MALEE2);
	MAPPER(B_MAGICSERIES);

	//txc corporation
	MAPPER(B_TXC_22211A);
	MAPPER(B_TXC_22211B);
	MAPPER(B_TXC_22211C);
	MAPPER(B_TXC_MXMDHTWO);
	MAPPER(B_TXC_TW);
	MAPPER(B_TXC_STRIKEWOLF);

	//sachen boards
	MAPPER(B_SACHEN_8259A);
	MAPPER(B_SACHEN_8259B);
	MAPPER(B_SACHEN_8259C);
	MAPPER(B_SACHEN_8259D);
	MAPPER(B_SACHEN_74LS374N);
	MAPPER(B_SACHEN_TCA01);
	MAPPER(B_SA_0036);
	MAPPER(B_SA_0037);
	MAPPER(B_SA_72007);
	MAPPER(B_SA_72008);

	//ffe
	MAPPER(B_FFE_MAPPER6);
	MAPPER(B_FFE_MAPPER8);
	MAPPER(B_FFE_MAPPER17);

	//extras
	MAPPER(B_NSF);
	MAPPER(B_FDS);
	MAPPER(B_HLEFDS);

	return(0);
}
