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
	copy->prev = NULL;
	/* iterate forwards over list which is copied from */
	while(currEle!=NULL){
		currCopyEle->data = currEle->data;
		if(currEle->next ==NULL) break;
		currCopyEle->next = malloc(sizeof(struct List));
		currEle = currEle->next;
		currCopyEle = currCopyEle->next;
	}
	/* initialize last ele as NULL */
	currCopyEle -> next = NULL;
	currCopyEle = copy;
	/* set backwards references */
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
	/* Special Case, index = -1 */
	if (pos<0){
		if(pos==-1){
			while(currentEle->next !=NULL){
				currentEle = currentEle ->next;
			}
			currentEle->next = malloc(sizeof(struct List));
			currentEle->next->data = data;
			currentEle->next->next = NULL;
			currentEle->next->prev = currentEle;
			return lst;
		}else{
			return NULL;
		}
	}


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

int main(int argc, char *argv[]){
	nodep lst=NULL,copy;
	int i;
	lst = malloc(sizeof(struct List));
	if(argc<=1){
		free(lst);
		return 1;
	}
	for(i=1; i<argc; i++){
		lst = insertAt(lst,i-1,argv[i]);
	}
	printlst(lst);
	copy=copyList(lst);
	deleteList(lst);
	while(copy->next!=NULL){
		copy=copy->next;
	}
	printf("REVERSE ORDER\n");
	while(copy!=NULL){
		printf("%s\n",(char*)copy->data);
			copy=copy->prev;
	}
	deleteList(copy);

	return 0;
}
