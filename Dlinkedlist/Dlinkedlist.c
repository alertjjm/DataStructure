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
	if (plist->comp == NULL) {
		FInsert(plist, data);
	}
	else {
		SInsert(plist, data);
	}
}
void FInsert(List* plist, LData data) {
	Node* tempnode = (Node*)malloc(sizeof(Node));
	tempnode->data = data;
	tempnode->next = plist->head->next;
	plist->head = tempnode;
	plist->numOfData++;
}
void SInsert(List* plist, LData data) {
	//
}

int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL)
		return FALSE;
	else {
		plist->cur = plist->head->next;
		plist->before = plist->head;
		*pdata = plist->head->next->data;
		return TRUE;
	}
}
int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;
	else {
		plist->before = plist->cur;
		plist->cur = plist->cur->next;
		*pdata = plist->cur->data;
		return TRUE;
	}
}
LData LRemove(List* plist) {
	LData data = plist->cur->data;
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	return data;
}
int LCount(List* plist) {

}
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2)) {

}