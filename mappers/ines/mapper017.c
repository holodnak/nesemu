#include "defines.h"
#include "mappers/mapper.h"

static u8 prg[4],chr[8],mirror;
static u8 irqenabled;
static int irqcycles;
static writefunc_t write4;

static void sync()
{
	int i;

	for(i=0;i<4;i++)
		mem_setprg8(8 + i * 2,prg[i]);
	for(i=0;i<8;i++)
		mem_setchr1(i,chr[i]);
	ppu_setmirroring(mirror);
}

static void write(u32 addr,u8 data)
{
	if(addr < 0x4020) {
		write4(addr,data);
		return;
	}
	switch(addr) {
		case 0x42FE:
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
		case 0x4504:
		case 0x4505:
		case 0x4506:
		case 0x4507:
			prg[addr & 3] = data;
			break;
		case 0x4510:
		case 0x4511:
		case 0x4512:
		case 0x4513:
		case 0x4514:
		case 0x4515:
		case 0x4516:
		case 0x4517:
			chr[addr & 7] = data;
			break;
	}
	sync();
	log_message("mapper17:  write to $%04X = $%02X\n",addr,data);
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
	mem_setwrite(4,write);
	nes_setsramsize(2);
	mem_setsram8(6,0);
	prg[0] = 0;
	prg[1] = 1;
	prg[2] = 0xFE;
	prg[3] = 0xFF;
	for(i=0;i<8;i++)
		chr[i] = i;
	mirror = MIRROR_V;
	irqenabled = 0;
	irqcycles = 0;
	sync();
}

static void state(int mode,u8 *data)
{
	int i;

	for(i=0;i<4;i++)
		STATE_U8(prg[i]);
	for(i=0;i<8;i++)
		STATE_U8(chr[i]);
	STATE_U8(mirror);
	STATE_U8(irqenabled);
	STATE_U32((u32)irqcycles);
	sync();
}

MAPPER_INES(17,reset,0,line,state);
