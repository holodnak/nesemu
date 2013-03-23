#include <string.h>
#include "mappers.h"

#define UNIF_BOARD(s,b)		{s,b}
#define UNIF_BOARD_END()	{0,-1}

typedef struct unif_boardid_s {
	const char *board;
	int boardid;
} unif_boardid_t;

static unif_boardid_t boards[] = {
	UNIF_BOARD("NES-NROM-128",			B_NROM),
	UNIF_BOARD("NES-NROM-256",			B_NROM),
	UNIF_BOARD_END()
};

u32 get_board_unif(char *str)
{
	int i;

	for(i=0;boards[i].boardid != -1;i++) {
		if(stricmp(str,boards[i].board) == 0)
			return(boards[i].boardid);
	}
	return(B_UNKNOWN);
}
