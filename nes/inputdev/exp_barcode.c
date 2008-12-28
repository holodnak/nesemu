#include "exp_barcode.h"
#include "system/system.h"

//static u8 data;

static u8 read(u32 addr)
{
	return(0);
}

static void update()
{
}

inputdev_t exp_barcode = {read,0,0,update};
