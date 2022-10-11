/*
	binaryTree

	Author: Marco Prescher
	Created on: 05.05.2021
*/

#pragma once

typedef int ItemType;
typedef struct Array Array_t;
typedef struct Node Node_t;

Array_t* getTreeValueArr(ItemType values[], int valuesLen);
void destroyTreeValueArr(Array_t** ppSeqArr);

Node_t* getBinaryTree(Array_t* pSeqArr);
void destroyBinaryTree(Node_t** ppRoot);

void printPreOrder(Node_t* pRoot);
void printInOrder(Node_t* pRoot);
void printPostOrder(Node_t* pRoot);

int getLeafCount(Node_t* pRoot);
int getTreeHeight(Node_t* pRoot);