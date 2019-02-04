#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lst {
	char name[20];
	int alter;
	struct lst *next;
} ListEle;

ListEle *einfuegen(ListEle *lst, const char *n, int a){
	ListEle *head = lst;
	if (lst == NULL){ /*special case, head == NULL */
		lst = malloc(sizeof(ListEle));
		/*assert(lst !=NULL); */
		strcpy(lst->name,n);
		lst->alter = a;
		lst->next = NULL;
		return lst;
	}
	while(lst->next != NULL){ /* loop till last ele*/
		lst = lst->next;
	}
	lst->next = malloc(sizeof(ListEle));
	strcpy(lst->next->name,n);
	lst->next->alter=a;
	lst->next->next = NULL;

	return head; 
}

int dopple(ListEle *lst, const char *n, int a){
	ListEle *cpyhelper = lst;
	while(lst != NULL){
		if((strcmp(lst->name,n) == 0) && lst->alter == a){
			cpyhelper = lst->next;
			lst->next = malloc(sizeof(ListEle));
			strcpy(lst->next->name,n);
			lst->next->alter = a;
			lst->next->next = cpyhelper;
			return 1;	
		}
		lst = lst->next;
	}
	return 0;
}

void befreie(ListEle *lst){
	ListEle *delHelper = lst;
	while(lst->next != NULL){
		lst = lst->next;
		free(delHelper);
		delHelper = lst;
	}
	free(lst);
}





int main(int argc, char **argv){
	ListEle *lst = NULL;
	lst = einfuegen(lst,"Willie",17);
	lst = einfuegen(lst,"Joendhard",17);
	lst = einfuegen(lst,"DingDong",17);
	dopple(lst,"Joendhard",17);
	dopple(lst,"Wusel",21);
	befreie(lst);
	return 0;
}
