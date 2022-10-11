/*
	test_binaryTree
	test_binarySearchTree

	Author: Marco Prescher
	Created on: 05.05.2021
*/

#include <stdio.h>

#include "binaryTree.h"
#include "binarySearchTree.h"

#define NR_OF_VALUES_10 10

#define FALSE 0
#define TRUE (!(FALSE))

// forward declarations --------------------------------------------------------------------------------------------------------
int test_binaryTree(int success, int* pErrCnt);
int test_binarySearchTree(int success, int* pErrCnt);
// -----------------------------------------------------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
	int test_binaryTreeActive = TRUE;
	int test_binarySearchTreeActive = TRUE;

	int success = TRUE;
	int errCnt = 0;

	if (test_binaryTreeActive) {
		printf("\n\n#### binaryTree ###########################################################################\n\n");

		success = test_binaryTree(success, &errCnt) && success;
	}
	if (test_binarySearchTreeActive) {
		printf("\n\n#### binarySearchTree #####################################################################\n\n");

		success = test_binarySearchTree(success, &errCnt) && success;
	}

	printf("\n\n\nTest finished with %d error(s)", (success == TRUE ? 0 : errCnt));

	// just to make it more beautiful ------------------------------------------------------------------------------------------
	printf("\n###########################################################################################\n\n");
	// -------------------------------------------------------------------------------------------------------------------------

	return 0;
}

// function definitions --------------------------------------------------------------------------------------------------------
int test_binaryTree(int success, int* pErrCnt) {

	// Test 1
	{
		printf("Testcase_1 *******************************************\n\n");

		ItemType values[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6, 10 };
		Array_t* pSeqArr = getTreeValueArr(values, NR_OF_VALUES_10);
		Node_t* pBinTree = getBinaryTree(pSeqArr);

		printf("print tree preOrder:\n");
		printPreOrder(pBinTree);
		printf("\n\n");

		printf("print Tree inOrder:\n");
		printInOrder(pBinTree);
		printf("\n\n");

		printf("print Tree postOrder:\n");
		printPostOrder(pBinTree);
		printf("\n\n");

		printf("Leaf count of BinTree: %d\n", getLeafCount(pBinTree));
		printf("Height of BinTree: %d\n\n", getTreeHeight(pBinTree));

		// free tree memory
		destroyBinaryTree(&pBinTree);
		if (pBinTree == NULL) {
			printf("pSeqArr: %s", (char*)pBinTree);
		}
		else {
			success = FALSE;
			(*pErrCnt)++;
		}

		printf("print tree preOrder:\n");
		printPreOrder(pBinTree);

		printf("print Tree inOrder:\n");
		printInOrder(pBinTree);

		printf("print Tree postOrder:\n");
		printPostOrder(pBinTree);

		printf("\nLeaf count of BinTree: %d\n", getLeafCount(pBinTree));
		printf("Height of BinTree: %d\n\n", getTreeHeight(pBinTree));

		// free Array_t struct memory
		destroyTreeValueArr(&pSeqArr);

		if (pSeqArr == NULL) {
			printf("pSeqArr: %s", (char*)pSeqArr);
		}
		else {
			success = FALSE;
			(*pErrCnt)++;
		}
	}

	printf("\n\n");

	// Test 2
	{
		printf("Testcase_2 *******************************************\n\n");

		Node_t* pBinTree = getBinaryTree(NULL);

		if (pBinTree == NULL) {
			printf("pBinTree: %s", (char*)pBinTree);
		}
		else {
			success = FALSE;
			(*pErrCnt)++;
		}
	}

	printf("\n\n");

	// Test 3
	{
		printf("Testcase_3 *******************************************\n\n");

		Array_t* pSeqArr = getTreeValueArr(NULL, NULL);
		Node_t* pBinTree = getBinaryTree(pSeqArr);

		if (pBinTree == NULL) {
			printf("pBinTree: %s", (char*)pBinTree);
		}
		else {
			success = FALSE;
			(*pErrCnt)++;
		}
	}

	printf("\n\n");

	return success;
}

int test_binarySearchTree(int success, int* pErrCnt) {

	// Test 1
	{
		printf("Testcase_1 *******************************************\n\n");

		// ItemType values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		// Array_t* pSeqArr = getTreeValueArr(values, NR_OF_VALUES_10);

		ItemType values[] = { 50, 30, 20, 40, 70, 60, 80 };

		Node_t* root = insert(NULL, 50);
		for (int i = 1; i < 7; i++) {
			insert(root, values[i]);
		}
		
		ItemType keys[] = { 10, 0, 100, 25, 60 };
		for (int i = 0; i < 5; i++) {
			ItemType key = keys[i];

			Node_t* pSucc = NULL;
			findSuccessor(root, &pSucc, key);
			if (pSucc != NULL) {
				printf("The successor of node with value %d is %d\n", key, getValueOfNode(pSucc));
			}
			else {
				printf("The successor doesn't exist for %d, pSucc = %s\n", key, (char*)pSucc);
			}


			Node_t* pPre = NULL;
			findPredecessor(root, &pPre, key);
			if (pPre != NULL) {
				printf("The predecessor of node with value %d is %d\n", key, getValueOfNode(pPre));
			}
			else {
				printf("The predecessor doesn't exist for %d, pPre = %s\n", key, (char*)pPre);
			}
		}
	}

	printf("\n\n");

	// Test 2
	{
		printf("Testcase_2 *******************************************\n\n");

		ItemType key = 2;

		Node_t* pSucc = NULL;
		findSuccessor(NULL, &pSucc, key);
		if (pSucc != NULL) {
			printf("The successor of node with value %d is %d\n", key, getValueOfNode(pSucc));
		}
		else {
			printf("The successor doesn't exist for %d, pSucc = %s\n", key, (char*)pSucc);
		}

		Node_t* pPre = NULL;
		findPredecessor(NULL, &pPre, key);
		if (pPre != NULL) {
			printf("The predecessor of node with value %d is %d\n", key, getValueOfNode(pPre));
		}
		else {
			printf("The predecessor doesn't exist for %d, pPre = %s\n", key, (char*)pPre);
		}
	}

	printf("\n\n");

	return success;
}
// -----------------------------------------------------------------------------------------------------------------------------