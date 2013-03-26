#ifndef __mmc6_h__
#define __mmc6_h__

#include "defines.h"

void mmc6_sync();
u8 mmc6_getprgbank(int n);
u8 mmc6_getchrbank(int n);
void mmc6_syncprg();
void mmc6_syncchr();
void mmc6_syncvram();
void mmc6_syncsram();
void mmc6_syncmirror();
void mmc6_sync();
void mmc6_init(void (*s)());
u8 mmc6_readsram(u32 addr);
void mmc6_writesram(u32 addr,u8 data);
void mmc6_write(u32 addr,u8 data);
void mmc6_line(int line,int pcycles);
void mmc6_state(int mode,u8 *data);

#endif
