#ifndef __LB_STACK_H__
#define __LB_STACK_H__
#define TRUE 1
#define FALSE 0

typedef char Data;

typedef struct _node {
	Data data;
	struct _node* next;
}Node;

typedef struct _listStack {
	Node* head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack); //스택 초기화
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);// peek 연산->헤드가 가리키는 노드의 데이터 반환
#endif