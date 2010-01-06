#include <stdio.h>
#include "../libconfig.h"

using namespace std;

int main(int argc,char *argv[])
{
	CConfig cfg;
	char *cfgfn = "test.config";

	if(argc < 2) {
			argc++;
			argv[1] = cfgfn;
	}

	if(argc < 2) {
			printf("usage:  %s [arguments] <file.config>\n\n",argv[0]);
			return(0);
	}
	cfg.Load(argv[1]);
	return(0);
}
