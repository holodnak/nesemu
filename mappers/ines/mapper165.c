#include "mappers/mapper.h"
#include "nes/ppu/ppu.h"
#include "mappers/chips/mmc3.h"

static u8 LatchA[2],LatchAState;
static u8 LatchB[2],LatchBState;

static void setchr4(int page,int bank)
{
	if(bank == 0)
		mem_setvram4(page,0);
	else
		mem_setchr4(page,bank);
}

static void sync()
{
//	int i;

	mmc3_syncprg(0xFF,0);
//	mmc3_syncchr(0xFF,0);
//	setchr4(0,LatchA[LatchAState]);
//	setchr4(4,LatchB[LatchBState]);
	setchr4(0,mmc3_getchrreg(LatchAState ? 2 : 0));
	setchr4(4,mmc3_getchrreg(LatchBState ? 6 : 4));
//////
	if(nes->rom->mirroring & 8)
	   ppu_setmirroring(MIRROR_4);
	else
		mmc3_syncmirror();
	mmc3_syncsram();
}

static void init(int hard)
{
	LatchA[0] = LatchA[1] = 0;
	LatchB[0] = LatchB[1] = 0;
	nes_setvramsize(1);
	mmc3_init(sync);
}

static void tile(u8 tile,int highpt)
{
	if((highpt & 1) == 0) {
		if(tile == 0xFD)
			LatchAState = 0;
		else if(tile == 0xFE)
			LatchAState = 1;
//		setchr4(0,LatchA[LatchAState]);
		setchr4(0,mmc3_getchrreg(LatchAState ? 2 : 0));
		
	}
	else {
		if(tile == 0xFD)
			LatchBState = 0;
		else if(tile == 0xFE)
			LatchBState = 1;
//		setchr4(4,LatchB[LatchBState]);
		setchr4(4,mmc3_getchrreg(LatchBState ? 6 : 4));
	}
}

static void state(int mode,u8 *data)
{
	mmc3_state(mode,data);
}

MAPPER_INES(165,init,tile,0,state);
