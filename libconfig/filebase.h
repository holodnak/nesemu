#ifndef __filebase_h__
#define __filebase_h__

class CFileBase {
	private:
	public:
		CFileBase() {
		}
		virtual ~CFileBase() {
		}
		virtual int Open(char *fn) = 0;
		virtual int Close() = 0;
		virtual long Read(void *dest,long len) = 0;
		virtual long Write(void *src,long len) = 0;
		virtual long Seek(long pos,int mode) = 0;
		virtual long Tell() = 0;
		virtual long Size() = 0;
};

class CStdioFile: public CFileBase {
	public:
		CFile();
		virtual ~CFile();
		virtual int Open(char *fn) = 0;
		virtual int Close() = 0;
		virtual long Read(void *dest,long len) = 0;
		virtual long Write(void *src,long len) = 0;
		virtual long Seek(long pos,int mode) = 0;
		virtual long Tell() = 0;
		virtual long Size() = 0;
}

class CFile: public CFileBase {
	public:
		CFile();
		virtual ~CFile();
		virtual int Open(char *fn) = 0;
		virtual int Close() = 0;
		virtual long Read(void *dest,long len) = 0;
		virtual long Write(void *src,long len) = 0;
		virtual long Seek(long pos,int mode) = 0;
		virtual long Tell() = 0;
		virtual long Size() = 0;
}

#endif
