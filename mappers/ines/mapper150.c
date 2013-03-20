#include "mappers/mapper.h"
#include "mappers/chips/latch.h"

static u8 prg,chr,mirror,latch;
static readfunc_t read4;
static writefunc_t write4;

static void sync()
{
	mem_setprg32(0x8,prg);
	mem_setchr8(0,chr);
	if(mirror < 2)
		ppu_setmirroring(mirror);
	else if(mirror == 2) {
		ppu_setmirroring2(0,1,1,1);
	}
	else if(mirror == 3)
		ppu_setmirroring(MIRROR_1L);
}


static u8 read(u32 addr)
{
	u8 ret = 0;

	if(addr < 0x4020) {
		return(read4(addr));
	}
	log_message("m150: read from $%04X\n",addr);
	return(ret);	
}

static void write(u32 addr,u8 data)
{
	if(addr < 0x4020) {
		write4(addr,data);
		return;
	}
	if((addr & 0xFF00) == 0x4100) {
		if((addr & 1) == 0) {
			latch = data;
		}
		else {
			switch(latch) {
				case 2:
					chr = (chr & ~8) | ((data & 1) << 3);
					prg = data & 1;
					break;
				case 4:
					chr = (chr & ~4) | ((data & 1) << 2);
					break;
				case 5:
					prg = data & 7;
					break;
				case 6:
					chr = (chr & ~3) | (data & 3);
					break;
				case 7:
					mirror = (data >> 1) & 3;
					break;
			}
			sync();
		}
	}
	else
		log_message("mapper150: UNHANDLED write to $%04X = $%02X\n",addr,data);
}

static void reset(int hard)
{
	read4 = mem_getread(4);
	write4 = mem_getwrite(4);
	mem_setread(4,read);
	mem_setwrite(4,write);
	prg = 0;
	chr = 0;
	mirror = MIRROR_V;
	sync();
}

static void state(int mode,u8 *data)
{
	STATE_U8(prg);
	STATE_U8(chr);
	STATE_U8(mirror);
	STATE_U8(latch);
	sync();
}

MAPPER_INES(150,reset,0,0,state);
