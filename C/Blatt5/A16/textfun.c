#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "textfun.h"

ListEle *wordlist = NULL;

void addPair(const char *such, const char *ersatz){
	ListEle *curr = wordlist;
	if(wordlist == NULL){ /* first insertion */
		wordlist = malloc(sizeof(ListEle));
		strcpy(wordlist->suchwort, such);
		strcpy(wordlist->ersetzwort, ersatz);
		wordlist->next= NULL;
	}else{
		while(curr->next!=NULL) curr = curr->next;
		curr->next = malloc(sizeof(ListEle));
		strcpy(curr->next->suchwort, such);
		strcpy(curr->next->ersetzwort, ersatz);
		curr->next->next = NULL;
	}
}

void clearlist(void){
	ListEle *curr = wordlist, *deleteHelper;
	while(curr!=NULL){
		deleteHelper = curr;
		curr = curr->next;
		free(deleteHelper);
	}
	wordlist = NULL;
}

struct Fundstelle find(const char *s){
	struct Fundstelle found;
	
	return found;
}
int main(int argc, char *argv[]){
	int i;
	char *such,*ersetz;
	if(argc<=1) return 1; /* No Replace Words */
	for(i=1;i<argc;i++){
		such = strtok(argv[i],"=");
		ersetz = strtok(NULL,"=");
		addPair(such,ersetz);
	}
	
	return 0;
}
