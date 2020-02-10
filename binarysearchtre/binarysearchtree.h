#pragma once
#include "BinaryTree2.h"
typedef BTData BSTData;
void BSTMakeAndInit(BTreeNode** pRoot);
BSTData BSTGetNodeData(BTreeNode* bst);
void BSTInsert(BTreeNode** pRoot, BSTData data);
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);