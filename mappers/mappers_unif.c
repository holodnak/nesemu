#include <string.h>
#include "mapperinc.h"

struct unif_board_s {
	const char *name;
	int boardid;
};

#define UNIF_BOARD_START()		static struct unif_board_s boards[] = {
#define UNIF_BOARD_END()		{0,-1}};
#define UNIF_BOARD(s,b)			{s,b},

UNIF_BOARD_START()

	//licensed
	//NROM boards
	UNIF_BOARD("NES-NROM",						B_NROM)
	UNIF_BOARD("NES-NROM-128",					B_NROM)
	UNIF_BOARD("NES-NROM-256",					B_NROM)
	UNIF_BOARD("HVC-NROM-128",					B_NROM)
	UNIF_BOARD("HVC-NROM-256",					B_NROM)
	UNIF_BOARD("IREM-NROM-128",				B_NROM)
	UNIF_BOARD("IREM-NROM-256",				B_NROM)
	UNIF_BOARD("TAITO-NROM-128",				B_NROM)
	UNIF_BOARD("TAITO-NROM-256",				B_NROM)
	UNIF_BOARD("KONAMI-NROM-128",				B_NROM)
	UNIF_BOARD("KONAMI-NROM-256",				B_NROM)

	//UxROM boards
	UNIF_BOARD("NES-UNROM",						B_UxROM)
	UNIF_BOARD("HVC-UNROM",						B_UxROM)
	UNIF_BOARD("IREM-UNROM",					B_UxROM)
	UNIF_BOARD("KONAMI-UNROM",					B_UxROM)
	UNIF_BOARD("NES-UOROM",						B_UxROM)
	UNIF_BOARD("HVC-UOROM",						B_UxROM)

	//CxROM boards
	UNIF_BOARD("NES-CNROM",						B_CxROM)

	//ExROM boards
	UNIF_BOARD("NES-EKROM",						B_ExROM)
	UNIF_BOARD("NES-ETROM",						B_ExROM)
	UNIF_BOARD("NES-ELROM",						B_ExROM)
	UNIF_BOARD("NES-EWROM",						B_ExROM)

	//SxROM boards
	UNIF_BOARD("NES-SAROM",						B_SxROM)
	UNIF_BOARD("NES-SBROM",						B_SxROM)
	UNIF_BOARD("NES-SCROM",						B_SxROM)
	UNIF_BOARD("NES-SEROM",						B_SxROM)
	UNIF_BOARD("NES-SFROM",						B_SxROM)
	UNIF_BOARD("NES-SGROM",						B_SxROM)
	UNIF_BOARD("NES-SHROM",						B_SxROM)
	UNIF_BOARD("NES-SJROM",						B_SxROM)
	UNIF_BOARD("NES-SKROM",						B_SxROM)
	UNIF_BOARD("NES-SLROM",						B_SxROM)
	UNIF_BOARD("NES-SNROM",						B_SxROM)
	UNIF_BOARD("NES-SOROM",						B_SxROM)
	UNIF_BOARD("NES-SUROM",						B_SxROM)
	UNIF_BOARD("NES-SXROM",						B_SxROM)

	//TxROM boards
	UNIF_BOARD("NES-TLROM",						B_TxROM)
	UNIF_BOARD("NES-TKROM",						B_TxROM)
	UNIF_BOARD("NES-TFROM",						B_TxROM)
	UNIF_BOARD("NES-TBROM",						B_TxROM)

	//HxROM boards
	UNIF_BOARD("NES-HKROM",						B_HxROM)

	//other boards
	UNIF_BOARD("NES-EVENT",						B_EVENT)

	//unlicensed
	//sachen
	UNIF_BOARD("UNL-SACHEN-8259A",			B_SACHEN_8259A)
	UNIF_BOARD("UNL-SACHEN-8259B",			B_SACHEN_8259B)
	UNIF_BOARD("UNL-SACHEN-8259C",			B_SACHEN_8259C)
	UNIF_BOARD("UNL-SACHEN-8259D",			B_SACHEN_8259D)
	UNIF_BOARD("UNL-SACHEN-74LS374N",		B_SACHEN_74LS374N)
	UNIF_BOARD("UNL-SACHEN-TCA01",			B_SACHEN_TCA01)
	UNIF_BOARD("UNL-SA-NROM",					B_SACHEN_TCA01)
	UNIF_BOARD("UNL-SA-0036",					B_SA_0036)
	UNIF_BOARD("UNL-SA-0037",					B_SA_0037)
	UNIF_BOARD("UNL-SA-72007",					B_SA_72007)
	UNIF_BOARD("UNL-SA-72008",					B_SA_72008)

	//txc corporation
	UNIF_BOARD("UNL-22211-A",					B_TXC_22211A)
	UNIF_BOARD("UNL-22211-B",					B_TXC_22211B)
	UNIF_BOARD("UNL-22211-C",					B_TXC_22211C)
	UNIF_BOARD("TXC-MXMDHTWO",					B_TXC_MXMDHTWO)
	UNIF_BOARD("TXC-TW",							B_TXC_TW)
	UNIF_BOARD("TXC-STRIKEWOLF",				B_TXC_STRIKEWOLF)

	//others
	UNIF_BOARD("MLT-CALTRON6IN1",				B_CALTRON6IN1)
	UNIF_BOARD("BTL-BIOMIRACLEA",				B_BIOMIRACLEA)
	UNIF_BOARD("BTL-MARIO1-MALEE2",			B_MARIO1_MALEE2)

UNIF_BOARD_END()

int get_unif_boardid(char *str)
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
