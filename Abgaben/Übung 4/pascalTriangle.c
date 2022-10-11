/*
	pascalTriangle

	Author: Marco Prescher
	Created on: 13.04.2021
*/

#include <stdio.h>
#include <math.h>

#include "pascalTriangle.h"

// forward declarations --------------------------------------------------------------------------------------------------------
static int getNumOfTriangle(int row, int column);
// -----------------------------------------------------------------------------------------------------------------------------

// function definitions --------------------------------------------------------------------------------------------------------

void pascalTriangle(int dim) {
	int spaceFac = sqrt(dim);

	if (dim > 0 && dim <= 20) {
		for (int row = 0; row < dim; row++) {
			for (int spaces = 0; spaces < spaceFac * (dim - row); spaces++) {
				printf(" ");
			}

			for (int col = 0; col <= row; col++) {
				printf("%*d", spaceFac * 2, getNumOfTriangle(row, col));
			}

			printf("\n");
		}
	}
	else {
		printf("Please enter a valid dimension for the triangle! -->\t 0 < dim <= 20");
	}
}

static int getNumOfTriangle(int row, int column) {
	if (row == 0 || column == 0 || row == column) {
		return 1;
	}
	else {
		return getNumOfTriangle(row - 1, column - 1) + getNumOfTriangle(row - 1, column);
	}
}

// -----------------------------------------------------------------------------------------------------------------------------