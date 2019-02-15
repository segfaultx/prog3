#include <stdlib.h>
#include <stdio.h>
typedef struct Stack{
	int val;
	struct Stack *next;
}stack;

stack* push(int val,stack *head){
	stack *newHead;
	if (head == NULL){
		head = malloc(sizeof(stack));
		head ->val = val;
		head -> next = NULL;
		return head;
	}
	newHead = malloc(sizeof(stack));
	newHead->val = val;
	newHead->next = head;
	return newHead;
}

stack* pop(stack *head){
	stack *newHead;
	newHead = head->next;
	printf("%d\n",head->val);
	free(head);
	return newHead;
}



int main(void){
	stack *head;
	head = NULL;
	printf("PUSHING 1\n");
	head = push(1,head);
	printf("PUSHING 3\n");
	head = push(3,head);
	printf("PUSHING 7\n");
	head = push(7,head);
	head = pop(head);
	head = pop(head);
	head = pop(head);


	return 0;
}
