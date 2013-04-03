#include "mappers/mapperinc.h"

#define SACHEN_8259A		0
#define SACHEN_8259B		1
#define SACHEN_8259C		2
#define SACHEN_8259D		3

static u8 cmd,reg[8];
static writefunc_t write4;
static void (*syncchr)();

static void sync()
{
	mem_setprg32(8,reg[5] & 7);
	if(reg[7]&1)
		ppu_setmirroring(MIRROR_V);
	else {
		switch(reg[7] & 6) {
			case 0: ppu_setmirroring(MIRROR_V); break;
			case 2: ppu_setmirroring(MIRROR_H); break;
			case 4: ppu_setmirroring2(0,1,1,1); break;
			case 6: ppu_setmirroring(MIRROR_1L); break;
		}
	}
	if(nes->rom->chrsize)
		syncchr();
}

static void syncchr_8259a()
{
	int i,j;

	for(i=0;i<4;i++) {
		if(reg[7] & 1)
			j = (reg[0] & 7) | ((reg[4] & 7) << 3);
		else
			j = (reg[i] & 7) | ((reg[4] & 7) << 3);
		mem_setchr2(i * 2,(j << 1) | (i & 1));
	}
}

static void syncchr_8259b()
{
	int i;

	for(i=0;i<4;i++) {
		if(reg[7] & 1)
			mem_setchr2(i * 2,(reg[0] & 7) | ((reg[4] & 7) << 3));
		else
			mem_setchr2(i * 2,(reg[i] & 7) | ((reg[4] & 7) << 3));
	}
}

static void syncchr_8259c()
{
	int i,j;

	for(i=0;i<4;i++) {
		if(reg[7] & 1)
			j = (reg[0] & 7) | ((reg[4] & 7) << 3);
		else
			j = (reg[i] & 7) | ((reg[4] & 7) << 3);
		mem_setchr2(i * 2,(j << 2) | (i & 3));
	}
}

static void syncchr_8259d()
{
	int i,j;

	for(i=0;i<4;i++) {
		j = reg[i] & 7;
		switch(i) {
			case 1: j |= (reg[4] & 1) << 4; break;
			case 2: j |= (reg[4] & 2) << 3; break;
			case 3: j |= ((reg[4] & 4) << 2) | ((reg[6] & 1) << 3); break;
		}
		mem_setchr1(i,j);
	}
	mem_setchr4(4,~0);
}

static void write(u32 addr,u8 data)
{
	if(addr < 0x4020) {
		write4(addr,data);
		return;
	}
	addr &= 0x101;
	if(addr == 0x100)
		cmd = data & 7;
	else {
		reg[cmd] = data;
		sync();
	}
}

static void reset(int revision,int hard)
{
	int i;

	switch(revision) {
		default:
		case SACHEN_8259A: syncchr = syncchr_8259a; break;
		case SACHEN_8259B: syncchr = syncchr_8259b; break;
		case SACHEN_8259C: syncchr = syncchr_8259c; break;
		case SACHEN_8259D: syncchr = syncchr_8259d; break;
	}
	write4 = mem_getwrite(4);
	for(i=4;i<8;i++)
		mem_setwrite(i,write);
	for(i=0;i<8;i++)
		reg[i] = 0;
	cmd = 0;
	sync();
}

static void reset_8259a(int hard)
{
	reset(SACHEN_8259A,hard);
}

static void reset_8259b(int hard)
{
	reset(SACHEN_8259B,hard);
}

static void reset_8259c(int hard)
{
	reset(SACHEN_8259C,hard);
}

static void reset_8259d(int hard)
{
	reset(SACHEN_8259D,hard);
}

static void state(int mode,u8 *data)
{
	STATE_ARRAY_U8(reg,8);
	STATE_U8(cmd);
	sync();
}

MAPPER(B_SACHEN_8259A,reset_8259a,0,0,0);
MAPPER(B_SACHEN_8259B,reset_8259b,0,0,0);
MAPPER(B_SACHEN_8259C,reset_8259c,0,0,0);
MAPPER(B_SACHEN_8259D,reset_8259d,0,0,0);
