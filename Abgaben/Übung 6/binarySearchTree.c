#pragma once
/*
	binarySearchTree

	Author: Marco Prescher
	Created on: 05.05.2021
*/

#include <stdio.h>

#include "binarySearchTree.h"

#define MAX_SIZE 500

typedef struct Array {
	int nrOfValues;
	ItemType* pValues;
} Array_t;

typedef struct Node {
	ItemType value;
	struct Node* pLeft;
	struct Node* pRight;

} Node_t;
// forward declarations --------------------------------------------------------------------------------------------------------
static Node_t* transformArrToBST(Array_t* pSeqArr, int start, int end);
static Node_t* createNode(ItemType value);
static Node_t* minValue(Node_t* pRoot);
static Node_t* maxValue(Node_t* pRoot);
// -----------------------------------------------------------------------------------------------------------------------------

// function definitions --------------------------------------------------------------------------------------------------------

Node_t* getBinarySearchTree(Array_t* pSeqArr) {
	Node_t* root = NULL;
	if (pSeqArr != NULL) {
		root = transformArrToBST(pSeqArr, 0, pSeqArr->nrOfValues - 1);
	}

	return root;
}

void destroyBinarySearchTree(Node_t** ppRoot) {
	if ((*ppRoot) != NULL) {
		destroyBinarySearchTree(&((*ppRoot)->pLeft));
		destroyBinarySearchTree(&((*ppRoot)->pRight));

		free((*ppRoot));
		(*ppRoot) = NULL;
	}
}

Node_t* insert(Node_t* pRoot, ItemType value) {
	if (pRoot != NULL) {
		if (value > pRoot->value) {
			pRoot->pRight = insert(pRoot->pRight, value);
		}
		else {
			pRoot->pLeft = insert(pRoot->pLeft, value);
		}
	}
	else {
		pRoot = createNode(value);
	}

	return pRoot;
}

void findSuccessor(Node_t* pRoot, Node_t** pSucc, ItemType key) {
	if (pRoot != NULL) {
		if (pRoot->value == key) {
			if (pRoot->pRight != NULL) {
				(*pSucc) = minValue(pRoot->pRight);
			}
		}
		else if (key < pRoot->value) {
			(*pSucc) = pRoot;
			findSuccessor(pRoot->pLeft, pSucc, key);
		}
		else {
			findSuccessor(pRoot->pRight, pSucc, key);
		}
	}
}

void findPredecessor(Node_t* pRoot, Node_t** pPreSucc, ItemType key) {
	if (pRoot != NULL) {
		if (pRoot->value == key) {
			if (pRoot->pLeft != NULL) {
				(*pPreSucc) = maxValue(pRoot->pLeft);
			}
		}
		else if (key < pRoot->value) {
			findPredecessor(pRoot->pLeft, pPreSucc, key);
		}
		else {
			(*pPreSucc) = pRoot;
			findPredecessor(pRoot->pRight, pPreSucc, key);
		}
	}
}

int getValueOfNode(Node_t* pRoot) {
	int value = 0;

	if (pRoot != NULL) {
		value = pRoot->value;
	}

	return value;
}

// intern functions ----------------------------------------
static Node_t* transformArrToBST(Array_t* pSeqArr, int start, int end) {
	Node_t* pRoot = NULL;

	if (pSeqArr != NULL && pSeqArr->nrOfValues != NULL && pSeqArr->pValues != NULL) {
		if (end <= MAX_SIZE && start < end) {
			int mid = (start + end) / 2;

			pRoot = createNode(pSeqArr->pValues[mid]);

			if (pRoot != NULL) {
				pRoot->pLeft = transformArrToBST(pSeqArr, start, mid - 1);
				pRoot->pRight = transformArrToBST(pSeqArr, mid + 1, end);
			}
		}
	}

	return pRoot;
}

static Node_t* createNode(ItemType value) {
	Node_t* pNewNode = (Node_t*)malloc(sizeof(Node_t));
	if (pNewNode != NULL) {
		pNewNode->value = value;
		pNewNode->pLeft = NULL;
		pNewNode->pRight = NULL;
	}

	return pNewNode;
}

static Node_t* minValue(Node_t* pRoot) {
	if (pRoot != NULL) {
		while (pRoot->pLeft) {
			pRoot = pRoot->pLeft;
		}
	}

	return pRoot;
}

static Node_t* maxValue(Node_t* pRoot) {
	if (pRoot != NULL) {
		while (pRoot->pRight) {
			pRoot = pRoot->pRight;
		}
	}

	return pRoot;
}

// -----------------------------------------------------------------------------------------------------------------------------