/*
	recursiveCalc
	pascalTriangle

	Author: Marco Prescher
	Created on: 13.04.2021
*/

#include <stdio.h>

#include "recursiveCalc.h"
#include "pascalTriangle.h"

#define FALSE 0
#define TRUE (!(FALSE))

// forward declarations --------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
	int test_recursiveCalc = 0;
	int test_pascalTriangle = 1;

	int success = TRUE;
	int errCnt = 0;

	if (test_recursiveCalc) {
		printf("\n\n#### recursiveCalc ########################################################################\n\n");

		// Test 1
		printf("sum of %d: %d\n\n", 5, recursiveCalc(5));

		// Test 2
		printf("sum of %d: %d\n\n", 0, recursiveCalc(0));

		// Test 3
		printf("sum of %d: %d\n\n", -5, recursiveCalc(-5));

		// Test 4
		printf("sum of %d: %d\n\n", 100, recursiveCalc(100));
	}
	if (test_pascalTriangle) {
		printf("\n\n#### pascalTriangle #######################################################################\n\n");

		// Test 1
		pascalTriangle(3);
		printf("\n\n");

		// Test 2
		pascalTriangle(6);
		printf("\n\n");

		// Test 3
		pascalTriangle(20);
		printf("\n\n");

		// Test 4
		pascalTriangle(-10);
		printf("\n\n");

		// Test 5
		pascalTriangle(0);
	}

	printf("\n\n\nTest finished with %d error(s)", (success == TRUE ? 0 : errCnt));

	// just to make it more beautiful ------------------------------------------------------------------------------------------
	printf("\n###########################################################################################\n\n");
	// -------------------------------------------------------------------------------------------------------------------------

	return 0;
}

// function definitions --------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------------------------