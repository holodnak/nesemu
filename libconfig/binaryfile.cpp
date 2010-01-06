#include <string.h>
#include "libconfig.h"

void CTextFile::Reset()
{
	memset(lineCache,0,sizeof(char**));
}

CTextFile::CTextFile()
{
	memset(filename,0,MAX_PATH);
}

CTextFile::CTextFile(char *fn)
{
	strncpy(filename,fn,MAX_PATH);
}

int CTextFile::FlushCache()
{
	int i;

	for(i=0;;i++) {
		if(lineCache[i] == 0)
			continue;
	}
}

long CTextFile::Read(void *dest,long len);
long CTextFile::Write(void *src,long len);

int CTextFile::ReadLine(char *dest,int num)
{
	int i;
	char *cache;

	Read(cache,num);
	for(i=0;i<
}
