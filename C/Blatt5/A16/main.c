#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "textfun.h"


int main(int argc,char* argv[]){
	char *such,*ersetz,usrinput[100]=" ";
	int i;
	enum {MAXINPUT = 100};
	if(argc<=1) return 1; /* too few arguments */
	for(i=1;i<argc;i++){
		such = strtok(argv[i],"=");
		ersetz = strtok(NULL,"=");
		addPair(such,ersetz);
	}
	while(fgets(usrinput,100,stdin)!=NULL){
		replaceAll(usrinput);
	}
	return 0;
}
