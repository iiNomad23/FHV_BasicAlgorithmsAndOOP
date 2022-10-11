/*
	triangularMatrix

	Author: Marco Prescher
	Created on: 06.04.2021
*/

#include <stdio.h>
#include <math.h>

#include "triangularMatrix.h"

// forward declarations --------------------------------------------------------------------------------------------------------
static int* fillArrOddNr(int* pTriMatrix, int n);
static int getRowsOfMatrix(int n);
static int getIdx(int row, int col);
// -----------------------------------------------------------------------------------------------------------------------------

// function definitions --------------------------------------------------------------------------------------------------------
void triangularMatrix(int n) {
	printf("\n");

	if (n > 1) {
		int nrOfElements = (n / 2) + 1;
		int* pTriMatrix = malloc(nrOfElements * sizeof(int));

		pTriMatrix = fillArrOddNr(pTriMatrix, n);

		int rows = getRowsOfMatrix(n);
		int elCnt = 0;
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col <= row && elCnt < nrOfElements - 1; col++) {
				printf("%d \t", pTriMatrix[getIdx(row, col)]);
				elCnt++;
			}

			printf("\n");
		}

		// free allocated memory of pTriMatrix
		free(pTriMatrix);
		pTriMatrix = NULL;
	}
	else {
		printf("-\n");
	}
}

static int* fillArrOddNr(int* pTriMatrix, int n) {
	int i = 0;
	int oddNr = 1;
	while (oddNr < n) {
		pTriMatrix[i] = oddNr;

		oddNr += 2;
		i++;
	}

	return pTriMatrix;
}
static int getRowsOfMatrix(int n) {
	int rows = sqrt(n);
	if ((rows * rows) < n) {
		rows++;
	}

	return rows;
}
// calculate index of given(row, column) in flattened array
static int getIdx(int row, int col) {
	if (col > row) {
		int temp = row;
		row = col;
		col = temp;
	}

	return  ((row * (row + 1)) / 2) + col;
}
// -----------------------------------------------------------------------------------------------------------------------------