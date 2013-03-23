#include "mapperinc.h"

struct ines_boardid_s {
	int num;
	int boardid;
};

#define INES_BOARD_START()		static struct ines_boardid_s boards[] = {
#define INES_BOARD_END()		{0,-1}};
#define INES_BOARD(n,b)			{n,b},

INES_BOARD_START()
	INES_BOARD(0,		B_NROM)
	INES_BOARD(1,		B_SxROM)
	INES_BOARD(2,		B_UxROM)
	INES_BOARD(3,		B_CxROM)
	INES_BOARD(4,		B_TxROM)
	INES_BOARD(7,		B_AxROM)
	INES_BOARD(9,		B_PxROM)
	INES_BOARD(107,	B_MAGICSERIES)
	INES_BOARD(150,	B_SACHEN_74LS374)
INES_BOARD_END()

int get_ines_boardid(int num)
{
	int i;

	for(i=0;boards[i].boardid != -1;i++) {
		if(num == boards[i].num)
			return(boards[i].boardid);
	}
	return(B_UNSUPPORTED);
}
