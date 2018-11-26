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
	struct Fundstelle found = {
				NULL,
				NULL
	};
	ListEle *currentWord = wordlist;
	while(currentWord!=NULL){
		if(strncmp(s,currentWord->suchwort,strlen(currentWord->suchwort))==0){
			found.stelleImSuchString = s;
			found.ersetzung = currentWord;
			break;
		}
		currentWord=currentWord->next;
	}
	return found;
}

int replaceAll(char *s){
	int count=0,i;
	char *curr=s, res[100]=" ";
	struct Fundstelle currFind;
	for(i=0;*curr;i++){
		currFind=find(curr);
		if(currFind.stelleImSuchString!=NULL){
			strcat(res,currFind.ersetzung->ersetzwort);
			i+=strlen(currFind.ersetzung->ersetzwort)-1;
			curr+=strlen(currFind.ersetzung->suchwort);
			currFind.ersetzung= NULL;
			currFind.stelleImSuchString=NULL;
			count++;
			continue;
		}else{
			res[i]=*curr;
		}
		curr++;
	}
	s = res;
	printf("%s\n",s);
	return count;
}
