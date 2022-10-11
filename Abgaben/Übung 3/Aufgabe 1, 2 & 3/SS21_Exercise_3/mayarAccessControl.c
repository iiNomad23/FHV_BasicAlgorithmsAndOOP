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
static int isMallocNull(int allowedCodes[], int allowedCodesLen);
static int hasAccess(int* allowedCodes[], int allowedCodesLen, int inputCode[], int validLen);
static int calcDiff(int allowedCode[], int inputCode[], int validLen);
// -----------------------------------------------------------------------------------------------------------------------------

// function definitions --------------------------------------------------------------------------------------------------------

void mayarAccessControl(int inputCode[], int validLen) {
	int* allowedCodes[] = {
		malloc(validLen * sizeof(int)),
		malloc(validLen * sizeof(int)),
		malloc(validLen * sizeof(int))
	};

	if (!isMallocNull(allowedCodes, REGISTERD_PATS)) {
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
	}

	// free allocated memory for codes
	for (int i = 0; i < REGISTERD_PATS; i++) {
		if (allowedCodes[i] != NULL) {
			free(allowedCodes[i]);
			allowedCodes[i] = NULL;
		}
	}
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

static int isMallocNull(int allowedCodes[], int allowedCodesLen) {
	int isNull = 0;

	for (int i = 0; i < allowedCodesLen && !isNull; i++) {
		if (allowedCodes[i] == NULL) {
			isNull = 1;
		}
	}

	return isNull;
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