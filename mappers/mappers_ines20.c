#include "mapperinc.h"

struct ines20_boardid_s {
	int num,sub;
	int boardid;
};

#define INES20_BOARD_START()	static struct ines20_boardid_s boards[] = {
#define INES20_BOARD_END()		{0,-1}};
#define INES20_BOARD(n,s,b)	{n,s,b},

INES20_BOARD_START()
	INES20_BOARD(0,	0,		B_NROM)
INES20_BOARD_END()

int get_ines20_boardid(int num,int sub)
{
	int i;

	for(i=0;boards[i].boardid != -1;i++) {
		if((num == boards[i].num) && (sub == boards[i].sub))
			return(boards[i].boardid);
	}
	return(B_UNSUPPORTED);
}
