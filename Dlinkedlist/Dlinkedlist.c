#include<stdio.h>
#include<stdlib.h>
#include"Dlinkedlist.h"

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->numOfData = 0;
	plist->comp = NULL;

}
void LInsert(List* plist, LData data) {
	Node* tempnode = (Node*)malloc(sizeof(Node));
	tempnode->data = data;
	tempnode->next = plist->head->next;
	plist->head = tempnode;

}
void FInsert(List* plist, LData data) {
	Node* tempnode = (Node*)malloc(sizeof(Node));
	
}

int LFirst(List* plist, LData* pdata) {

}
int LNext(List* plist, LData* pdata) {

}
LData LRemove(List* plist) {

}
int LCount(List* plist) {

}
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2)) {

}