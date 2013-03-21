#include "mappers/mapper.h"
#include "nes/nes.h"

static u8 prg,chr;
static writefunc_t write4;

static void sync()
{
	mem_setprg32(8,prg);
	mem_setchr8(0,chr);
}

static void write_4000(u32 addr,u8 data)
{
	if(addr < 0x4020) {
		write4(addr,data);
		return;
	}
	if((addr & 0xFF00) == 0x4100) {
		prg = (data & 0x38) >> 3;
		chr = (data & 7) | ((data & 0x40) >> 3);
		sync();
	}
//	log_message("mapper113:  write 4:  $%04X = $%02X\n",addr,data);
}

static void init(int hard)
{
	write4 = mem_getwrite(4);
	mem_setwrite(4,write_4000);
	prg = 0;
	chr = 0;
	sync();
}

static void state(int mode,u8 *data)
{
	STATE_U8(prg);
	STATE_U8(chr);
	sync();
}

MAPPER_INES(113,init,0,0,state);
