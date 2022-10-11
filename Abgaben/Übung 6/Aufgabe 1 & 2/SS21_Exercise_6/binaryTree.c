/*
	binaryTree

	Author: Marco Prescher
	Created on: 05.05.2021
*/

#include <stdio.h>

#include "binaryTree.h"

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
static Node_t* transform(Array_t* pSeqArr, Node_t* pRoot, int i);
static Node_t* createNode(ItemType value);
// -----------------------------------------------------------------------------------------------------------------------------


// function definitions --------------------------------------------------------------------------------------------------------

Node_t* getBinaryTree(Array_t* pSeqArr) {
	Node_t* root = NULL;
	if (pSeqArr != NULL) {
		root = transform(pSeqArr, root, 0);
	}

	return root;
}

void destroyBinaryTree(Node_t** ppRoot) {
	if ((*ppRoot) != NULL) {
		destroyBinaryTree(&((*ppRoot)->pLeft));
		destroyBinaryTree(&((*ppRoot)->pRight));

		free((*ppRoot));
		(*ppRoot) = NULL;
	}
}

Array_t* getTreeValueArr(ItemType values[], int valuesLen) {
	Array_t* pSeqArr = (Array_t*)malloc(sizeof(Array_t));

	if (pSeqArr != NULL) {
		pSeqArr->nrOfValues = valuesLen;
		pSeqArr->pValues = values;
	}

	return pSeqArr;
}

void destroyTreeValueArr(Array_t** ppSeqArr) {
	if ((*ppSeqArr) != NULL) {
		free((*ppSeqArr));
		(*ppSeqArr) = NULL;
	}
}

void printPreOrder(Node_t* pRoot) {
	if (pRoot != NULL) {
		printf("%d ", pRoot->value);
		printPreOrder(pRoot->pLeft);
		printPreOrder(pRoot->pRight);
	}
}

void printInOrder(Node_t* pRoot) {
	if (pRoot != NULL) {
		printInOrder(pRoot->pLeft);
		printf("%d ", pRoot->value);
		printInOrder(pRoot->pRight);
	}
}

void printPostOrder(Node_t* pRoot) {
	if (pRoot != NULL) {
		printPostOrder(pRoot->pLeft);
		printPostOrder(pRoot->pRight);
		printf("%d ", pRoot->value);
	}
}

int getLeafCount(Node_t* pRoot) {
	int leaveCnt = 0;

	if (pRoot != NULL) {
		leaveCnt = 1;

		if (pRoot->pLeft != NULL && pRoot->pRight != NULL) {
			leaveCnt = getLeafCount(pRoot->pLeft) + getLeafCount(pRoot->pRight);
		} 
	}

	return leaveCnt;
}

int getTreeHeight(Node_t* pRoot) {
	int height = 0;

	if (pRoot != NULL) {
		int leftHeight = getTreeHeight(pRoot->pLeft);
		int rightHeight = getTreeHeight(pRoot->pRight);
		
		if (leftHeight > rightHeight) {
			height = leftHeight + 1;
		}
		else {
			height = rightHeight + 1;
		}
	}

	return height;
}

// intern functions ----------------------------------------
static Node_t* transform(Array_t* pSeqArr, Node_t* pRoot, int i) {
	if (pSeqArr != NULL && pSeqArr->nrOfValues != NULL && pSeqArr->pValues != NULL) {
		if (pSeqArr->nrOfValues <= MAX_SIZE && i < pSeqArr->nrOfValues) {
			Node_t* pNewNode = createNode(pSeqArr->pValues[i]);

			if (pNewNode != NULL) {
				pRoot = pNewNode;

				pRoot->pLeft = transform(pSeqArr, pRoot->pLeft, 2 * i + 1);
				pRoot->pRight = transform(pSeqArr, pRoot->pRight, 2 * i + 2);
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

// -----------------------------------------------------------------------------------------------------------------------------