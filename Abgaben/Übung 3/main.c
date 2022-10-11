/*
	triangularMatrix
	insertSort
	mayarAccessControl

	Author: Marco Prescher
	Created on: 06.04.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "triangularMatrix.h"
#include "sortings.h"
#include "mayarAccessControl.h"

#define FALSE 0
#define TRUE (!(FALSE))

#define NR_OF_VALUES_10 10
#define NR_OF_VALUES_100 100


int main(int argc, char* argv[]) {
	int test_triangularMatrix = 0;
	int test_insertSort = 0;
	int test_mayarAccessControl = 1;

	int success = TRUE;
	int errCnt = 0;

	if (test_triangularMatrix) {
		printf("\n\n#### triangularMatrix #####################################################################\n\n");

		// Test 1 ---------------
		printf("\nTestcase 1\n\n");
		triangularMatrix(20);
		printf("\n********************\n\n");

		// Test 2 ---------------
		printf("\nTestcase 2\n\n");
		triangularMatrix(15);
		printf("\n********************\n\n");

		// Test 3 ---------------
		printf("\nTestcase 3\n\n");
		triangularMatrix(0);
		printf("\n********************\n\n");

		// Test 4 ---------------
		printf("\nTestcase 4\n\n");
		triangularMatrix(1);
		printf("\n********************\n\n");

		// Test 5 ---------------
		printf("\nTestcase 5\n\n");
		triangularMatrix(2);
		printf("\n********************\n\n");

		// Test 6 ---------------
		printf("\nTestcase 6\n\n");
		triangularMatrix(100);
		printf("\n********************\n\n");
	}
	if (test_insertSort) {
		printf("\n\n#### insertSort ###########################################################################\n\n");

		srand(time(0)); // Use current time as seed for random generator

		// Test 1 ---------------
		{
			printf("\nTestcase 1\n\n");

			int values[NR_OF_VALUES_10] = { 0 };
			for (int i = 0; i < NR_OF_VALUES_10; i++) {
				values[i] = rand();
			}

			printf("number of steps: %d\n", insertSort(values, NR_OF_VALUES_10));

			printf("Sorted array: ");
			for (int i = 0; i < NR_OF_VALUES_10; i++) {
				printf("%d ", values[i]);
			}

			printf("\n********************\n\n");
		}

		// Test 2 ---------------
		{
			printf("\nTestcase 2\n\n");

			int values[NR_OF_VALUES_100] = { 0 };
			for (int i = 0; i < NR_OF_VALUES_100; i++) {
				values[i] = rand();
			}

			printf("number of steps: %d\n", insertSort(values, NR_OF_VALUES_100));

			printf("Sorted array: ");
			for (int i = 0; i < NR_OF_VALUES_100; i++) {
				printf("%d ", values[i]);
			}

			printf("\n********************\n\n");
		}

		// Test 3 ---------------
		{
			printf("\nTestcase 3\n\n");

			int values[NR_OF_VALUES_10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			printf("number of steps: %d\n", insertSort(values, NR_OF_VALUES_10));

			printf("Sorted array: ");
			for (int i = 0; i < NR_OF_VALUES_10; i++) {
				printf("%d ", values[i]);
			}

			printf("\n********************\n\n");
		}

		// Test 4 ---------------
		{
			printf("\nTestcase 4\n\n");

			int values[NR_OF_VALUES_10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
			printf("number of steps: %d\n", insertSort(values, NR_OF_VALUES_10));

			printf("Sorted array: ");
			for (int i = 0; i < NR_OF_VALUES_10; i++) {
				printf("%d ", values[i]);
			}

			printf("\n********************\n\n");
		}
	}
	if (test_mayarAccessControl) {
		printf("\n\n#### mayarAccessControl ###################################################################\n\n");

		// Test 1 ---------------
		{
			printf("\nTestcase 1\n\n");

			// code of person who wants to enter
			const char* local_MRxCode[] = {
				{"+-----------------+"},
				{"|                 |"},
				{"|      *    *     |"},
				{"|    ** ***  *** *|"},
				{"| * *      *    * |"},
				{"|* *              |"},
				{"+-----------------+"},
			};

			int* inputCode = malloc(COL_PATTERN_MATRIX * sizeof(int));
			mayarAccessControl(convertMatrixToArray(inputCode, COL_PATTERN_MATRIX, local_MRxCode, ROW_PATTERN_MATRIX), COL_PATTERN_MATRIX);

			free(inputCode);

			printf("\n********************\n\n");
		}

		// Test 2 ---------------
		{
			printf("\nTestcase 2\n\n");

			// code of person who wants to enter
			const char* local_MRxCode[] = {
				{"+-----------------+"},
				{"|*****************|"},
				{"|                 |"},
				{"|                 |"},
				{"|                 |"},
				{"|                 |"},
				{"+-----------------+"},
			};

			int* inputCode = malloc(COL_PATTERN_MATRIX * sizeof(int));
			mayarAccessControl(convertMatrixToArray(inputCode, COL_PATTERN_MATRIX, local_MRxCode, ROW_PATTERN_MATRIX), COL_PATTERN_MATRIX);

			free(inputCode);

			printf("\n********************\n\n");
		}
	}

	printf("\n\n\nTest finished with %d error(s)", (success == TRUE ? 0 : errCnt));

	// just to make it more beautiful ------------------------------------------------------------------------------------------
	printf("\n###########################################################################################\n\n");
	// -------------------------------------------------------------------------------------------------------------------------

	return 0;
}