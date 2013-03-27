#include "mappers/mapperinc.h"

static u8 prg,chr,mirror,mode;
static u8 irqenabled;
static int irqcycles;
static writefunc_t write4;

static void sync()
{
	mem_setprg16(0x8,prg);
	mem_setprg16(0xC,0xFF);
	if(mode && nes->rom->chrsize)
		mem_setchr8(0,chr & 3);
	else
		mem_setvram8(0,0);//(0,chr & 3);
	ppu_setmirroring(mirror);
}

static void write_4000(u32 addr,u8 data)
{
	if(addr < 0x4020) {
		write4(addr,data);
		return;
	}

	switch(addr) {
		case 0x42FE:
			mode = data & 0x80;
			mirror = (data & 0x10) ? MIRROR_1H : MIRROR_1L;
			break;
		case 0x42FF:
			mirror = (data & 0x10) ? MIRROR_H : MIRROR_V;
			break;
		case 0x4501:
			irqenabled = data & 1;
			break;
		case 0x4502:
			irqcycles = (irqcycles & 0xFF00) | data;
			break;
		case 0x4503:
			irqenabled = 1;
			irqcycles = (irqcycles & 0x00FF) | (data << 8);
			break;
	}
	log_message("mapper6 write: $%04X = $%02X\n",addr,data);
	sync();
}

static void write(u32 addr,u8 data)
{
	log_message("mapper6 write: $%04X = $%02X\n",addr,data);
	prg = data >> 2;
	chr = data & 3;
	sync();
}

static void line(int line,int pcycles)
{
	if(irqenabled == 0)
		return;
	irqcycles -= pcycles / 3;
	if(irqcycles < 0) {
		irqenabled = 0;
		dead6502_irq();
	}
}

static void reset(int hard)
{
	int i;

	write4 = mem_getwrite(4);
	mem_setwrite(4,write_4000);
	for(i=8;i<0x10;i++)
		mem_setwrite(i,write);
	nes_setsramsize(2);
	mem_setvram8(0,0);
	mem_setsram8(6,0);
	prg = 0;
	chr = 0;
	mode = 0;
	irqenabled = 0;
	irqcycles = 0;
	sync();
}

static void state(int mode,u8 *data)
{
	STATE_U8(prg);
	STATE_U8(chr);
	STATE_U8(mirror);
	STATE_U8(mode);
	STATE_U8(irqenabled);
	STATE_INT(irqcycles);
	sync();
}

MAPPER(B_FFE_MAPPER6,reset,0,line,state);
