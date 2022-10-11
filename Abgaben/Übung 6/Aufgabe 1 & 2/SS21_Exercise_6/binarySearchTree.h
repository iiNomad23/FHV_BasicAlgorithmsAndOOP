/*
	binarySearchTree

	Author: Marco Prescher
	Created on: 05.05.2021
*/

#pragma once

typedef int ItemType;
typedef struct Array Array_t;
typedef struct Node Node_t;

Node_t* getBinarySearchTree(Array_t* pSeqArr);
void destroyBinarySearchTree(Node_t** ppRoot);

Node_t* insert(Node_t* pRoot, ItemType value);

void findSuccessor(Node_t* pRoot, Node_t** pSucc, ItemType key);
void findPredecessor(Node_t* pRoot, Node_t** pPreSucc, ItemType key);

int getValueOfNode(Node_t* pRoot);