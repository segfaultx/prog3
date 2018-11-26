#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "textfun.h"


int main(int argc,char* argv[]){

	char *such,*ersetz,usrinput[100]=" ";
	int i;
	enum {MAXINPUT = 100};
	FILE *stream;
	ListEle *wordlist=NULL;
	if(argc>1){
		for(i=1;i<argc;i++){
			such = strtok(argv[i],"=");
			ersetz = strtok(NULL,"=");
			addPair(such,ersetz);
		}
		while(fgets(usrinput,100,stdin)!=NULL){
			replaceAll(usrinput);
		}
		stream = fopen("glogomir.txt","w+");
		if(!stream) return 1;
		wordlist = getwordlist();
		while(wordlist!=NULL){
			fprintf(stream, "%s=%s\n",wordlist->suchwort,wordlist->ersetzwort);
			wordlist= wordlist->next;
		}
		fclose(stream);
	}else{
		stream = fopen("glogomir.txt","r");
		if(!stream) return 1;
		while(fgets(usrinput,MAXINPUT,stream)!=NULL){
			sscanf(usrinput,"%[^\n]",usrinput);
			such = strtok(usrinput,"=");
			ersetz= strtok(NULL,"=");
			addPair(such,ersetz);
		}
		fclose(stream);
		while(fgets(usrinput,MAXINPUT,stdin)!=NULL){
			replaceAll(usrinput);
		}
	}
	clearList();
	return 0;
}
