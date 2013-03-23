#include "mappers.h"

#define INES20_BOARD(n,s,b)	{n,s,b}
#define INES20_BOARD_END()		{-1,-1,-1}

typedef struct ines20_boardid_s {
	int num,sub;
	int boardid;
} ines20_boardid_t;

static ines20_boardid_t boards[] = {
	INES20_BOARD(0,	0,		B_NROM),
	INES20_BOARD_END()
};

u32 get_board_ines20(int num,int sub)
{
	int i;

	for(i=0;boards[i].boardid != -1;i++) {
		if((num == boards[i].num) && (sub == boards[i].sub))
			return(boards[i].boardid);
	}
	return(B_UNKNOWN);
}
