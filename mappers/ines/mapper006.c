#include "defines.h"
#include "mappers/mapper.h"

static u8 prg,chr,mirror,mode;
static u8 irqenabled;
static int irqcycles;
static writefunc_t write4;

static void sync()
{
	mem_setprg16(0x8,prg);
	mem_setprg16(0xC,0xFF);
	if(mode == 0)
		mem_setvram8(0,chr & 3);
	else
		mem_setchr8(0,chr & 3);
	ppu_setmirroring(mirror);
}

void write_4000(u32 addr,u8 data)
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
	chr = data;
	prg = data >> 2;
//	reg = data;
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
	mem_setsram8(6,0);
	prg = 0;
	chr = 0;
	mode = 0;
	irqenabled = 0;
	sync();
}

static void state(int mode,u8 *data)
{
//	STATE_U8(reg);
//	STATE_U8(mode);
}

MAPPER_INES(6,reset,0,line,state);
