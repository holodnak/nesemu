#include <string.h>
#include "mappers.h"

struct unif_board_s {
	const char *name;
	int boardid;
};

#define UNIF_BOARD_START()		static struct unif_board_s boards[] = {
#define UNIF_BOARD_END()		{0,-1}};
#define UNIF_BOARD(s,b)			{s,b},

UNIF_BOARD_START()

	//NROM boards
	UNIF_BOARD("NES-NROM",					B_NROM)
	UNIF_BOARD("NES-NROM-128",				B_NROM)
	UNIF_BOARD("NES-NROM-256",				B_NROM)
	UNIF_BOARD("HVC-NROM-128",				B_NROM)
	UNIF_BOARD("HVC-NROM-256",				B_NROM)
	UNIF_BOARD("IREM-NROM-128",			B_NROM)
	UNIF_BOARD("IREM-NROM-256",			B_NROM)
	UNIF_BOARD("TAITO-NROM-128",			B_NROM)
	UNIF_BOARD("TAITO-NROM-256",			B_NROM)
	UNIF_BOARD("KONAMI-NROM-128",			B_NROM)
	UNIF_BOARD("KONAMI-NROM-256",			B_NROM)

	//UxROM boards
	UNIF_BOARD("NES-UNROM",					B_UxROM)
	UNIF_BOARD("HVC-UNROM",					B_UxROM)
	UNIF_BOARD("IREM-UNROM",				B_UxROM)
	UNIF_BOARD("KONAMI-UNROM",				B_UxROM)
	UNIF_BOARD("NES-UOROM",					B_UxROM)
	UNIF_BOARD("HVC-UOROM",					B_UxROM)

	//CxROM boards
	UNIF_BOARD("NES-CNROM",					B_CxROM)

	//SxROM boards
	UNIF_BOARD("NES-SLROM",					B_SxROM)
	UNIF_BOARD("NES-SKROM",					B_SxROM)

	//PxROM boards
	UNIF_BOARD("NES-PNROM",					B_PxROM)
	UNIF_BOARD("NES-PEEOROM",				B_PxROM)

UNIF_BOARD_END()

u32 get_unif_boardid(char *str)
{
	int i;

	for(i=0;boards[i].boardid != -1;i++) {
		if(stricmp(str,boards[i].name) == 0)
			return(boards[i].boardid);
	}
	return(B_UNSUPPORTED);
}

const char *get_unif_board(int idx)
{
	if(boards[idx].boardid == -1 || boards[idx].name == 0)
		return(0);
	return(boards[idx].name);
}
