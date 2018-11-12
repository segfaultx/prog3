#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List {
	void *data;
	struct List *next;
	struct List *prev;
}*list;

typedef struct List *nodep;


/* function to print all void pointers from list */
void printlst(nodep lst){
	while(lst!=NULL){
		printf("%s\n",(char*)lst->data);
		lst = lst->next;
	}
}

/*function to delete list */
void deleteList(nodep lst){
	nodep deleteHelper;
	while(lst!=NULL){
		deleteHelper = lst;
		lst = lst->next;
		free(deleteHelper);
	}
}

nodep copyList(nodep lst){
	nodep copy, currEle=lst,currCopyEle;
	copy = malloc(sizeof(struct List));
	currCopyEle = copy;
	while(currEle!=NULL){
		currCopyEle->data = currEle->data;
		if(currEle->next ==NULL) break;
		currCopyEle->next = malloc(sizeof(struct List));
		currEle = currEle->next;
		currCopyEle = currCopyEle->next;
	}
	currCopyEle -> next = NULL;
	currCopyEle = copy;
	while(currCopyEle->next!=NULL){
		currCopyEle->next->prev = currCopyEle;
		currCopyEle = currCopyEle->next;
	}
	return copy;
}


/* function to delete ele at given index */
nodep deleteAt(nodep lst, int pos){
	int currPos = 0;
	nodep currentEle = lst, deleteHelper;
	/* Special case: Remove head */
	if(pos == 0){
		deleteHelper = currentEle;
		currentEle = currentEle->next;
		currentEle->prev = NULL;
		free(deleteHelper);
		/* return currentEle because it became new head */
		return currentEle;
	}else{
		while(currPos != (pos-1)){
			currentEle = currentEle ->next;
			currPos++;
		}
		/* remove middle element and link current and next of to delete */	
		if(currentEle->next->next !=NULL){
			deleteHelper = currentEle->next;
			currentEle->next = currentEle->next->next;
			currentEle->next->prev = currentEle;
			free(deleteHelper);
			return lst;
		}
		free(currentEle->next);
		currentEle->next = NULL;
	}
	return NULL;
}

/* function to insert data at given index */
nodep insertAt(nodep lst, int pos, void *data){
	int currPos = 0;
	nodep currentEle = lst, copyHelper;
	/* if list is empty return NULL to signal error */
	if(lst == NULL) return NULL;
	/* insert into head */
	if (pos == 0){
		lst->data = data;
		lst->next = NULL;
		lst->prev = NULL;
		return lst;
	}
	/* insert at given position */
	while(currPos!=pos-1){
		currentEle = currentEle ->next;
		currPos++;
		if(currentEle->next == NULL && (currPos < (pos-1))){
			return NULL;
		}	
	}
	/* allocate memory & set data as well as prev and next */
	if(currentEle->next != NULL){
		copyHelper = currentEle->next;
		copyHelper->prev = currentEle;
		currentEle->next = malloc(sizeof(struct List));
		currentEle->next->data = data;
		currentEle->next->next = copyHelper;
		return lst;
	}
	currentEle->next = malloc(sizeof(struct List));
	currentEle->next->data = data;
	currentEle->next->next = NULL;
	currentEle->next->prev = currentEle;

	return lst;
}

int main(void){
	char *woerter[]={"Wort1","Wort2","Wort3","WORT4"};
	nodep lst=NULL,copy;
	lst = malloc(sizeof(struct List));
	lst=insertAt(lst,0,woerter[0]);
	lst=insertAt(lst,1,woerter[1]);
	lst=insertAt(lst,2,woerter[2]);
	lst=insertAt(lst,1,woerter[3]);
	printlst(lst);
	copy=copyList(lst);
	printf("DELETE AT INDEX 1\n");
	lst=deleteAt(lst,1);
	printlst(lst);
	printf("DELETE AT INDEX 0\n");
	lst=deleteAt(lst,0);
	printlst(lst);
	deleteList(lst);
	printf("COPIED LIST\n");
	printlst(copy);

	return 0;
}
