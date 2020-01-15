#include<stdio.h>
#include<stdlib.h>
#include"ListBaseStack_my.h"

void StackInit(Stack* pstack) {
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = pstack->head;
	pstack->head = newnode;
}

Data SPop(Stack* pstack) {
	Node* temp_node;
	Data temp_data;
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}	
	temp_data = pstack->head->data;
	temp_node = pstack->head;
	pstack->head = pstack->head->next;
	free(temp_node);
	return temp_data;
}

Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!\n");
		exit(-1);
	}

	return pstack->head->data;
}
