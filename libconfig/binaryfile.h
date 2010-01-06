#ifndef __binaryfile_h__
#define __binaryfile_h__

#include <string.h>
#include "filebase.h"

class CBinaryFile: public CFile {
	public:
		CBinaryFile();
		CBinaryFile(char *fn);
		~CBinaryFile();

}

#endif
