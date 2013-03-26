#include "mappers/mapperinc.h"

static u8 cmd,prg,chr,mirror;
static readfunc_t read4;
static writefunc_t write4;

static void sync()
{
	mem_setprg16(0x8,(prg << 1) | 0);
	mem_setprg16(0xC,(prg << 1) | 1);
	mem_setchr8(0,chr);
//	log_message("sync: prg = $%X (L:%X H:%X), chr = $%X, chr / 2 = $%X\n",prg,(prg<<1),(prg<<1)|1,chr,chr/2);
	if(mirror)
		ppu_setmirroring(MIRROR_V);
	else
		ppu_setmirroring(MIRROR_V);
}

static u8 read(u32 addr)
{
	if(addr < 0x4020)
		return(read4(addr));
	if(addr == 0x4100)
		return(~cmd & 0x3F);
	return(0);
}

static void write(u32 addr,u8 data)
{
	if(addr < 0x4020) {
		write4(addr,data);
		return;
	}
//	data &= 7;
	if((addr & 0x4101) == 0x4100) {
		cmd = data & 7;
	}
	else if((addr & 0x4101) == 0x4101) {
//		log_message("sachen-74ls374n:  write cmd %d = $%02X\n",cmd,data);
		switch(cmd) {
			case 0:
				prg = 0;
				chr = 3;
				break;
			case 2:
				prg = data & 1;
				chr &= ~8;
				chr |= (data & 1) << 3;
				break;
			case 4:
				chr &= ~4;
				chr |= (data & 1) << 2;
				break;
			case 5:
				prg = data & 1;
				break;
			case 6:
				chr &= ~3;
				chr |= data & 3;
				break;
			case 7:
				mirror = (data >> 1) & 3;
				break;
			default:
				log_message("sachen-74ls374n:  unknown write cmd %d (data = $%02X)\n",cmd,data);
				break;
		}
	}
	sync();
}

static void reset(int hard)
{
	read4 = mem_getread(4);
	write4 = mem_getwrite(4);
	mem_setread(4,read);
	mem_setwrite(4,write);
	cmd = 0;
	prg = 0;
	chr = 3;
	mirror = 0;
	sync();
}

static void state(int mode,u8 *data)
{
	STATE_U8(cmd);
	STATE_U8(prg);
	STATE_U8(chr);
	STATE_U8(mirror);
	sync();
}

MAPPER(B_SACHEN_74LS374N,reset,0,0,state);
