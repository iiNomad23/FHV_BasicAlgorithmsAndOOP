/*
	linkedList

	Author: Marco Prescher
	Created on: 20.04.2021
*/

#include <stdio.h>

#include "linkedList.h"


#define NR_OF_VALUES_5 5
#define NR_OF_VALUES_1 1

#define FALSE 0
#define TRUE (!(FALSE))

// forward declarations --------------------------------------------------------------------------------------------------------
void createList(Node_t* pHead, value_t* values, int valuesLen);

int test_linkedList(Node_t* pHead, value_t values[], int valuesLen);
// -----------------------------------------------------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
	int test_int_linkedListActive = 1;

	int success = TRUE;
	int errCnt = 0;

	if (test_int_linkedListActive) {
		printf("\n\n#### int linkedList #######################################################################\n\n");

		// Test 1 -----------------------------------------------------------------
		Node_t* testNode = createNode(10);
		if (testNode->value == 10 && testNode->pNext == NULL) {
			printf("Test 1 successful\n");
		}
		else {
			printf("Test 1 failed\n");
			success = FALSE;
			errCnt++;
		}
		printf("******************************************************\n\n");

		// Test 2 -----------------------------------------------------------------
		{
			Node_t* pHead = NULL;
			value_t values[] = { 10, 20, 30, 40, 50 };

			success = test_linkedList(pHead, values, NR_OF_VALUES_5) && success;
			if (success) {
				printf("Test 2 successful\n");
			}
			else {
				printf("Test 2 failed\n");
				errCnt++;
			}
			printf("******************************************************\n\n");
		}

		// Test 3 -----------------------------------------------------------------
		{
			Node_t* pHead = NULL;
			value_t values[] = { 0 };

			success = test_linkedList(pHead, values, NR_OF_VALUES_1) && success;
			if (success) {
				printf("Test 3 successful\n");
			}
			else {
				printf("Test 3 failed\n");
				errCnt++;
			}
			printf("******************************************************\n\n");
		}
	}
	else {
		// Test 4 -----------------------------------------------------------------
		{
			Node_t* pHead = NULL;
			value_t values[] = { 10.01, 20.01, 30, 40.01, 50 };

			success = test_linkedList(pHead, values, NR_OF_VALUES_5) && success;
			if (success) {
				printf("Test 4 successful\n");
			}
			else {
				printf("Test 4 failed\n");
				errCnt++;
			}
			printf("******************************************************\n\n");
		}
	}

	printf("\n\n\nTest finished with %d error(s)", (success == TRUE ? 0 : errCnt));

	// just to make it more beautiful ------------------------------------------------------------------------------------------
	printf("\n###########################################################################################\n\n");
	// -------------------------------------------------------------------------------------------------------------------------

	return 0;
}

// function definitions --------------------------------------------------------------------------------------------------------
void createList(Node_t* pHead, value_t* values, int valuesLen) {
	for (int i = 0; i < valuesLen; i++) {
		insertFront3(pHead, createNode(values[i]));
	}
}

int test_linkedList(Node_t* pHead, value_t values[], int valuesLen) {
	int success = 1;

	createList(&pHead, values, valuesLen);

	printList(pHead);
	printf("\n\n");

	Node_t* testNode = getNode(pHead, 2);
	if (testNode != NULL) {
		if (testNode->value != 30) {
			success = FALSE;
		}

		// Test insertFront -------------------------------------
		printf("insertFront\n");
		success = insertFront(&pHead, 100) && success;
		if (pHead->value != 100) {
			success = FALSE;
		}
		printList(pHead);
		printf("\n\n");

		// Test insertBefore ------------------------------------
		printf("insertBefore\n");
		success = insertBefore(&pHead, testNode, 88) && success;
		printList(pHead);
		printf("\n\n");

		// Test deleteValues -> deleteAllOcc = FALSE ------------
		printf("insertBefore\n");
		success = insertBefore(&pHead, testNode, 88) && success;
		printList(pHead);
		printf("\n\n");

		printf("deleteValues, occ -> FALSE\n");
		deleteValues(&pHead, 88, FALSE);
		printList(pHead);
		printf("\n\n");

		// Test deleteValues -> deleteAllOcc = TRUE -------------
		printf("insertBefore x 2\n");
		success = insertBefore(&pHead, testNode, 88) && success;
		success = insertBefore(&pHead, testNode, 30) && success;
		success = insertBefore(&pHead, testNode, 88) && success;
		printList(pHead);
		printf("\n\n");

		printf("deleteValues, occ -> TRUE\n");
		deleteValues(&pHead, 88, TRUE);
		printList(pHead);
		printf("\n\n");

		// Test inverseList -------------------------------------
		printf("inverseList\n");
		inverseList(&pHead);
		printList(pHead);
		printf("\n\n");

		// Test sortList ----------------------------------------
		printf("add 3x nodes\n");
		success = insertBefore(&pHead, testNode, 13) && success;
		success = insertBefore(&pHead, testNode, 22) && success;
		success = insertBefore(&pHead, testNode, 5) && success;
		printList(pHead);
		printf("\n\n");

		printf("sortList\n");
		sortList(&pHead);
		printList(pHead);
		printf("\n\n");

		// Test deleteList --------------------------------------
		printf("deleteList\n");
		deleteList(&pHead);
		printList(pHead);
		printf("\n\n");
	}

	return success;
}
// -----------------------------------------------------------------------------------------------------------------------------