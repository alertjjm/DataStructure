#include<stdio.h>
#include<stdlib.h>
#include "binarysearchtree.h"
void BSTMakeAndInit(BTreeNode** pRoot) {
	*pRoot = NULL;
}
BSTData BSTGetNodeData(BTreeNode* bst) {
	return bst->data;
}
void BSTInsert(BTreeNode** pRoot, BSTData data) {
	BTreeNode* newnode = MakeBTreeNode();
	SetData(newnode, data);
	BTreeNode* cur = *pRoot;
	BTreeNode* before = NULL;
	if (*pRoot == NULL) {
		*pRoot = newnode;
		return;
	}
	while (cur!=NULL) {
		if (cur->data > data) {
			before = cur;
			cur = cur->left;
		}
		else {
			before = cur;
			cur = cur->right;
		}
	}
	
	if (before->data > data) {
		MakeLeftSubTree(before, newnode);
	}
	else {
		MakeRightSubTree(before, newnode);
	}
}
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target) {
	BTreeNode* cur = bst;
	while (!(cur->left == NULL&&cur->right == NULL)) {
		if (cur->data == target)
			return cur;
		else if (cur->data > target)
			cur = cur->left;
		else
			cur = cur->right;
	}
	return NULL;
}