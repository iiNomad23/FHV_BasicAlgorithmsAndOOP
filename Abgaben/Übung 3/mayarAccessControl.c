/*
	mayarAccessControl

	Author: Marco Prescher
	Created on: 06.04.2021
*/

#include <stdio.h>
#include <stdlib.h>

#include "mayarAccessControl.h"

#define REGISTERD_PATS 3
#define MAX_DELTA 2

// forward declarations --------------------------------------------------------------------------------------------------------
static int calcDiff(int allowedCode[], int inputCode[], int validLen);
static int hasAccess(int* allowedCodes[], int allowedCodesLen, int inputCode[], int validLen);
// -----------------------------------------------------------------------------------------------------------------------------

// function definitions --------------------------------------------------------------------------------------------------------

void mayarAccessControl(int inputCode[], int validLen) {
	int* allowedCodes[] = {
		malloc(validLen * sizeof(int)),
		malloc(validLen * sizeof(int)),
		malloc(validLen * sizeof(int))
	};

	// registerd patterns
	char* local_codes[][ROW_PATTERN_MATRIX] = {
		{// MrMayerPat
			"+-----------------+", 
			"|                 |",
			"|      *    *     |",
			"|    ** ***  **  *|",
			"|   *      *   ** |",
			"|***              |",
			"+-----------------+"
		},
		{// MsMayerPat
			"+-----------------+",
			"|             *** |",
			"|     **   ***    |",
			"|*****  ***       |",
			"|                 |",
			"|                *|",
			"+-----------------+"
		},
		{// SonMayerPat
			"+-----------------+",
			"|                 |",
			"|      **   *     |",
			"|   ***  *** **  *|",
			"| *            ** |",
			"|* *              |",
			"+-----------------+"
		},
	};

	for (int i = 0; i < REGISTERD_PATS; i++) {
		allowedCodes[i] = convertMatrixToArray(allowedCodes[i], validLen, local_codes[i], ROW_PATTERN_MATRIX);
	}

	printf("%s", hasAccess(allowedCodes, REGISTERD_PATS, inputCode, validLen) ? "Access allowed" : "Access denied");

	free(allowedCodes[0]);
	allowedCodes[0] = NULL;

	free(allowedCodes[1]);
	allowedCodes[1] = NULL;

	free(allowedCodes[2]);
	allowedCodes[2] = NULL;
}

int* convertMatrixToArray(int allowedCode[], int validLen, char* matrix[], int rows) {
	for (int row = 1; row < rows - 1; row++) {
		for (int col = 1; col < validLen - 1; col++) {
			if (matrix[row][col] == '*') {
				allowedCode[col] = row;
			}
		}
	}

	return allowedCode;
}

static int hasAccess(int* allowedCodes[], int allowedCodesLen, int inputCode[], int validLen) {
	int allowed = 0;

	for (int codeIdx = 0; codeIdx < allowedCodesLen && !allowed; codeIdx++) {
		int i = 0;

		while (i < validLen && !allowed) {
			int diff = calcDiff(allowedCodes[codeIdx], inputCode, validLen);

			if (diff <= MAX_DELTA) {
				allowed = 1;
			}

			i++;
		}
	}

	return allowed;
}

static int calcDiff(int allowedCode[], int inputCode[], int validLen) {
	int diff = 0;

	for (int i = 1; i < validLen - 1; i++) {
		if (abs(inputCode[i] - allowedCode[i]) > 1) {
			diff += 1;
		}
	}

	return diff;
}

// -----------------------------------------------------------------------------------------------------------------------------