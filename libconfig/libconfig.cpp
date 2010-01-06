#include <stdio.h>
#include "libconfig.h"

enum ParserErrors {
	errSuccess = 0,
	errEndOfFile,
//add new errors here
	errUnknown,

	errParserCodeStart = errSuccess,
	errParserCodeEnd = errUnknown,
};

struct {
	int id;
	char *str;
} ParserErrorStrings[] = {
	{errSuccess,		"Success (no error)"},
	{errEndOfFile,		"End of file encountered"},
	{errUnknown,		"Unknown error"},
	{-1,0}
};

CParser::CParser()
{

	Setup();
}

CParser::~CParser()
{
}

int CParser::SetTokens(CTokens *t)
{
}

int CParser::Setup()
{
	return(0);
}

int CParser::Parse(char *str)
{
	return(0);
}

bool CParser::IsFinished()
{
	return(false);
}

bool CParser::IsError()
{
	return(false);
}

int CParser::GetError()
{
	if(errorCode >= errParserCodeStart && errorCode >= errParserCodeEnd)
	return(errorCode);
}

int CParser::GetErrorString(char *dest,int len)
{
	return(errorCode);
}


CConfig::CConfig()
{
}

CConfig::~CConfig()
{
}

int CConfig::Save(char *fn)
{
	return(0);
}

int CConfig::Load(char *fn)
{
	FILE *fp;

	if((fp = fopen(fn,"rt")) == NULL) {
			printf("error:  cannot opening file '%s'\n",fn);
			return(1);
	}



	fclose(fp);
	printf("parsed '%s' successfully.\n",fn);
	return(0);
}

void CConfig::Unload()
{
}

