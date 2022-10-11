/*
	mayarAccessControl

	Author: Marco Prescher
	Created on: 06.04.2021
*/

#pragma once

#define ROW_PATTERN_MATRIX 7
#define COL_PATTERN_MATRIX 19

void mayarAccessControl(int inputCode[], int validLen);
int* convertMatrixToArray(int allowedCode[], int validLen, char* matrix[], int rows);