#include "mappers.h"

#define INES_BOARD(n,b)			{n,b}
#define INES_BOARD_END()		{-1,-1}

typedef struct ines_boardid_s {
	int num;
	int boardid;
} ines_boardid_t;

static ines_boardid_t boards[] = {
	INES_BOARD(0,	B_NROM),
	INES_BOARD(1,	B_SxROM),
	INES_BOARD(2,	B_UxROM),
	INES_BOARD(3,	B_CxROM),
	INES_BOARD(4,	B_TxROM),
	INES_BOARD_END()
};

u32 get_board_ines(int num)
{
	int i;

	for(i=0;boards[i].boardid != -1;i++) {
		if(num == boards[i].num)
			return(boards[i].boardid);
	}
	return(B_UNKNOWN);
}
