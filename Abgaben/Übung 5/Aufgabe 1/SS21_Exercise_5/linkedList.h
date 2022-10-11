/*
	linkedList

	Author: Marco Prescher
	Created on: 20.04.2021
*/

#pragma once

typedef int value_t;

typedef struct Node {
	value_t value;
	struct Node* pNext;
} Node_t;

Node_t* createNode(value_t value);
Node_t* getNode(Node_t* pHead, int index);
int insertFront(Node_t** ppHead, const value_t value);
int insertBefore(Node_t** ppHead, Node_t* pPrevNode, const value_t value);
int deleteValues(Node_t** ppHead, const value_t Value, int deleteAllOcc);
int deleteList(Node_t** ppHead);
void printList(const Node_t* pHead);
int inverseList(Node_t** ppHead);
int sortList(Node_t** ppHead);

int removeFirst(Node_t** ppHead);
Node_t* findPredecessor(Node_t* pHead, Node_t* pNode);
void insertFront2(Node_t** ppHead, const value_t value);
void insertFront3(Node_t** ppHead, Node_t* pNode);