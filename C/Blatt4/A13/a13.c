#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Person {
	char name[25];
	struct Person *next;
};

typedef struct Person person;

int main(int argc, char *argv[]){
	char curr[25];
	person *currPerson = NULL, *merk;
	int i;
	merk=currPerson;
	while(scanf("%s",curr)!=EOF){
		if(currPerson == NULL){
			currPerson= malloc (sizeof(struct Person));
			if(!currPerson) return 1; /* allocation error*/
			strcpy(currPerson->name, curr);
			currPerson->next = NULL;
			merk = currPerson;
		}else{	
			/* find last piece in list*/
			while(currPerson->next !=NULL){
			currPerson = currPerson->next;
			}
			/* allocate next person memory*/
			currPerson->next = malloc(sizeof(struct Person));
			/*copy string into new person struct*/
			if(!currPerson->next) return 1;
			strcpy(currPerson->next->name, curr);
			currPerson->next->next = NULL;
		}
	}
	/* set last's element next to first element */
	currPerson->next->next = merk;
	currPerson = merk;
	/* iterate over ring structure | WIP */
	while(currPerson->name != currPerson->next->name){
		for(i=1; i<(argc-2); i++){
			currPerson = currPerson->next;
		}
		printf("%s\n",currPerson->next->name);
		merk = currPerson->next->next;
		free((currPerson->next));
		currPerson->next = merk;
	}
	printf("%s\n", currPerson->name);
	free(currPerson);
	return 0;
}
