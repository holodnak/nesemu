#ifndef __textfile_h__
#define __textfile_h__

#include <string.h>
#include "filebase.h"

class CCache {
	private:
		void	*data;
		long	size;
	public:
		CCache(long s);
		virtual ~CCache();

};

class CFileCache {

};

class CTextFile: public CFile {
	private:
		char filename[MAX_PATH];
		char **lines;
		int lineNum;
		char **lineCache;
		int lineCacheNum;
	protected:
		void Reset();
	public:
		CTextFile();
		CTextFile(char *fn);
		~CTextFile();

		long Read(void *dest,long len);
		long Write(void *src,long len);

		int ReadLine(char *dest,int len);

};

class CBinaryFile: public CFile {
	public:
		CBinaryFile();
		CBinaryFile(char *fn);
		~CBinaryFile();

}
