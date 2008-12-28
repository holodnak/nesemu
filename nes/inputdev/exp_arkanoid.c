#include "exp_arkanoid.h"
#include "system/system.h"

//static u8 data;

static u8 read(u32 addr)
{
	int offset = 98;

	return(offset);
}

static void update()
{
}

inputdev_t exp_arkanoid = {read,0,0,update};
