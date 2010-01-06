#ifndef __libconfig_h__
#define __libconfig_h__

#include <string.h>

class CToken {
	private:
		char name[512];
		int id;
	public:
		CToken(char *n,int i) {
			strncpy(name,n,512);
			id = i;
		}

		~CToken();

		char *Name(){	return(name);	}
		int ID() 	{	return(id);	}
};

class CEntry {
	protected:
		CEntry	*prev,*next;
	public:
		CEntry() {
			prev = 0;
			next = 0;
		}
		CEntry(CEntry *p = NULL,CEntry *n = NULL) {
			prev = p;
			next = n;
		}
		~CEntry();
		CEntry *Prev()	{	return(prev);	}
		CEntry *Next()	{	return(next);	}
};

class CLinkedList {
	private:
		CEntry		*head,*tail;
	protected:
	public:
		CLinkedList();
		~CLinkedList();
		int Add(CEntry *e);
		int Insert(CEntry *e,int pos);
		int Delete(int id);
		int Clear();
};

class CTokenEntry: public CEntry {
	public:
		CTokenEntry();
		~CTokenEntry();

};

class CTokens {
	private:
		CTokenEntry		*list;
	protected:
	public:
		CTokens();
		~CTokens();
};

class CParser {
	private:
		int errorCode;
	public:
		CParser();
		~CParser();

		int SetTokens(CTokens *t);
		int Setup();
		int Parse(char *str);

		bool IsFinished();
		bool IsError();
		int GetError();
		int GetErrorString(char *dest,int len);
};

class CConfig {
	public:
		CConfig();
		~CConfig();

		int Save(char *fn);
		int Load(char *fn);
		void Unload();

		int Parse(char *fn);
		int ParseLine(char *fn);
};

#endif
