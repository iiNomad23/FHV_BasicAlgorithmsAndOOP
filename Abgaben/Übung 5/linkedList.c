/*
	linkedList

	Author: Marco Prescher
	Created on: 20.04.2021
*/

#include <stdio.h>

#include "linkedList.h"

// forward declarations --------------------------------------------------------------------------------------------------------
static int isInteger(value_t value);
// -----------------------------------------------------------------------------------------------------------------------------

// function definitions --------------------------------------------------------------------------------------------------------

Node_t* createNode(value_t value) {
	Node_t* pNewNode = malloc(sizeof(Node_t));

	if (pNewNode != NULL) {
		pNewNode->pNext = NULL;
		pNewNode->value = value;
	}

	return pNewNode;
}

Node_t* getNode(Node_t* pHead, int index) {
	Node_t* pCurr = NULL;

	if (pHead != NULL) {
		pCurr = pHead;

		int i = 1;
		while (pCurr != NULL && i <= index) {
			pCurr = pCurr->pNext;
			i++;
		}
	}

	return pCurr;
}

int insertFront(Node_t** ppHead, const value_t value) {
	int success = 0;

	if (ppHead != NULL) {
		Node_t* pNewNode = malloc(sizeof(Node_t));

		if (pNewNode != NULL) {
			pNewNode->pNext = (*ppHead);
			pNewNode->value = value;

			(*ppHead) = pNewNode;

			success = 1;
		}
	}

	return success;
}

int insertBefore(Node_t** ppHead, Node_t* pPrevNode, const value_t value) {
	int success = 0;

	if (ppHead != NULL && pPrevNode != NULL) {
		Node_t* pCurr = (*ppHead);
		while (pCurr != pPrevNode) {
			pCurr = pCurr->pNext;
		}

		Node_t* pNewNode = malloc(sizeof(Node_t));

		if (pNewNode != NULL) {
			pNewNode->pNext = pCurr->pNext;
			pNewNode->value = value;

			pCurr->pNext = pNewNode;

			success = 1;
		}
	}

	return success;
}

int deleteValues(Node_t** ppHead, const value_t value, int deleteAllOcc) {
	int success = 0;

	if (ppHead != NULL) {
		Node_t* pCurr = (*ppHead);

		if (deleteAllOcc) {
			while (pCurr != NULL && pCurr->pNext != NULL) {
				if (pCurr->pNext->value == value) {
					Node_t* pTemp = pCurr->pNext;
					pCurr->pNext = pTemp->pNext;
					free(pTemp);
				}
				else {
					pCurr = pCurr->pNext;
				}
			}
		}
		else {
			int nodeRemoved = 0;

			while (pCurr != NULL && pCurr->pNext != NULL && !nodeRemoved) {
				if (pCurr->pNext->value == value) {
					Node_t* pTemp = pCurr->pNext;
					pCurr->pNext = pTemp->pNext;
					free(pTemp);

					nodeRemoved = 1;
				}
				else {
					pCurr = pCurr->pNext;
				}
			}
		}

		success = 1;
	}

	return success;
}

int deleteList(Node_t** ppHead) {
	int success = 0;

	if (ppHead != NULL) {
		while (*ppHead != NULL) {
			Node_t* pNextNode = (*ppHead)->pNext;
			free(*ppHead);
			*ppHead = pNextNode;

			success = 1;
		}
	}

	return success;
}

void printList(const Node_t* pHead) {
	if (pHead != NULL) {
		Node_t* pCurr = pHead;

		while (pCurr != NULL) {
			if (isInteger(pCurr->value)) {
				printf("%d ", (int)pCurr->value);
			}
			else {
				printf("%.2f ", (double)pCurr->value);
			}
			
			pCurr = pCurr->pNext;
		}
	}
	else {
		printf("LinkedList is empty ... pHead = NULL");
	}
}

int inverseList(Node_t** ppHead) {
	int success = 0;

	if (ppHead != NULL) {
		Node_t* pCurr = *ppHead;
		Node_t* pPrev = NULL;
		Node_t* pNext = NULL;

		while (pCurr != NULL) {
			pNext = pCurr->pNext;
			pCurr->pNext = pPrev;

			pPrev = pCurr;
			pCurr = pNext;
		}

		*ppHead = pPrev;

		success = 1;
	}

	return success;
}

int sortList(Node_t** ppHead) {
	int success = 0;

	if (ppHead != NULL) {
		Node_t* pCurr = NULL;
		Node_t* pNext = NULL;

		int listLen = getListLength((*ppHead));
		int nodesToSort = listLen;

		for (int i = 0; i < listLen - 1; i++) {
			pCurr = (*ppHead);
			pNext = (*ppHead)->pNext;

			for (int j = 1; j < nodesToSort; j++) {
				if (pCurr->value > pNext->value) {
					value_t tempValue = pCurr->value;
					pCurr->value = pNext->value;
					pNext->value = tempValue;
				}

				pCurr = pCurr->pNext;
				pNext = pNext->pNext;
			}

			nodesToSort--;
		}
	}

	return success;
}





// additional function definitions ------------------------------
int getListLength(const Node_t* pHead) {
	int len = 0;

	if (pHead != NULL) {
		Node_t* pCurr = pHead;

		while (pCurr != NULL) {
			pCurr = pCurr->pNext;
			len++;
		}
	}

	return len;
}

int removeFirst(Node_t** ppHead) {
	int success = 0;

	if (ppHead != NULL) {
		Node_t* pNextNode = (*ppHead)->pNext;
		free(*ppHead);
		*ppHead = pNextNode;

		success = 1;
	}
	

	return success;
}

Node_t* findPredecessor(Node_t* pHead, Node_t* pNode) {
	// TODO NUll check
	if (pHead == pNode) {
		return NULL;
	}

	Node_t* pCurr = pHead;
	Node_t* pPrev = NULL;
	while (pCurr != pNode) {
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}

	return pPrev;
}

void insertFront2(Node_t** ppHead, const value_t value) {
	Node_t* pNewNode = malloc(sizeof(Node_t));
	pNewNode->pNext = (*ppHead);
	pNewNode->value = value;

	(*ppHead) = pNewNode;
}

void insertFront3(Node_t** ppHead, Node_t* pNode) {
	pNode->pNext = (*ppHead);
	(*ppHead) = pNode;
}

static int isInteger(value_t value) {
	int truncated = (int)value;

	if (truncated == value) {
		truncated = 1;
	}
	else {
		truncated = 0;
	}

	return truncated;
}
// -----------------------------------------------------------------------------------------------------------------------------