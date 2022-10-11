/*
	findCharLeft
	findCharRight
	findCharRandom

	Author: Marco Prescher
	Created on: 24.03.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE 0
#define TRUE (!(FALSE))

// forward declarations ---------------------------------------------------------------------------------------------------------
int getLengthOfString(const char* str);

int findCharLeft(const char* str, char ch);
int findCharRight(const char* str, char ch);
int findCharRight_2(const char* str, char ch);
int findCharRandom(const char* str, char ch);
// -----------------------------------------------------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
	int test_findCharLeft = 1;
	int test_findCharRight = 0;
	int test_findCharRight_2 = 0;
	int test_findCharRandom = 0;

	// int success = TRUE;
	// int errCnt = 0;
	
	if (test_findCharLeft) {
		printf("\n\n#### findCharLeft #########################################################################\n\n");

		{
			const char* str = "abc";
			char ch = 'b';
			printf("\nTestcase 1\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharLeft(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "abc";
			char ch = 'a';
			printf("\nTestcase 2\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharLeft(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "abc";
			char ch = 'c';
			printf("\nTestcase 3\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharLeft(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "abc";
			char ch = 'd';
			printf("\nTestcase 4\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharLeft(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "";
			char ch = 'i';
			printf("\nTestcase 5\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharLeft(str, ch);
			printf("pos of ch: %d\n********************", pos);
		} 
		{
			const char* str = "ewniobpmwEDasdgkRLÖPQAM;D";
			char ch = 'k';
			printf("\nTestcase 6\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharLeft(str, ch);
			printf("pos of ch: %d\n********************", pos);
		} 
	}
	if (test_findCharRight) {
		printf("\n\n#### findCharRight ########################################################################\n\n");

		{
			const char* str = "abc";
			char ch = 'b';
			printf("\nTestcase 1\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRight(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "abc";
			char ch = 'a';
			printf("\nTestcase 2\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRight(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "abc";
			char ch = 'c';
			printf("\nTestcase 3\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRight(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "abc";
			char ch = 'd';
			printf("\nTestcase 4\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRight(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "";
			char ch = 'i';
			printf("\nTestcase 5\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRight(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "ewniobpmwEDasdgkRLÖPQAM;D";
			char ch = 'k';
			printf("\nTestcase 6\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRight(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
	}
	if (test_findCharRight_2) {
		printf("\n\n#### findCharRight_2 ######################################################################\n\n");

		{
			const char* str = "abc";
			char ch = 'b';
			printf("\nTestcase 1\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRight_2(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "abc";
			char ch = 'a';
			printf("\nTestcase 2\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRight_2(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "abc";
			char ch = 'c';
			printf("\nTestcase 3\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRight_2(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "abc";
			char ch = 'd';
			printf("\nTestcase 4\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRight_2(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "";
			char ch = 'i';
			printf("\nTestcase 5\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRight_2(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "ewniobpmwEDasdgkRLÖPQAM;D";
			char ch = 'k';
			printf("\nTestcase 6\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRight_2(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
	}
	if (test_findCharRandom) {
		printf("\n\n#### findCharRandom #######################################################################\n\n");

		srand(time(0)); // Use current time as seed for random generator

		{
			const char* str = "abc";
			char ch = 'b';
			printf("\nTestcase 1\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRandom(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "abc";
			char ch = 'a';
			printf("\nTestcase 2\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRandom(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "abc";
			char ch = 'c';
			printf("\nTestcase 3\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRandom(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "abc";
			char ch = 'd';
			printf("\nTestcase 4\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRandom(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "";
			char ch = 'i';
			printf("\nTestcase 5\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRandom(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
		{
			const char* str = "ewniobpmwEDasdgkRLÖPQAM;D";
			char ch = 'k';
			printf("\nTestcase 6\n\nInput: \"%s\", '%c'\n\n", str, ch);

			int pos = findCharRandom(str, ch);
			printf("pos of ch: %d\n********************", pos);
		}
	}

	// printf("\n\n\nTest finished with %d error(s)", (success == TRUE ? 0 : errCnt));

	// just to make it more beautiful ------------------------------------------------------------------------------------------
	printf("\n###########################################################################################\n\n");
	// -------------------------------------------------------------------------------------------------------------------------

	return 0;
}

// function definitions --------------------------------------------------------------------------------------------------------
int getLengthOfString(const char* str) {
	int i = 0;

	while (str[i] != '\0') {
		i++;
	}

	return i;
}

/*
	Hier wird von links nach rechts der string durch iteriert bis der 
	passende Character gefunden wurde.
		
	O-Notation
		BestCase     O(1)
		AvrCase      O(n)
		WorstCase    O(n)
*/
int findCharLeft(const char* str, char ch) {
	int pos = -1;
	int nOfSteps = 1;

	for (int i = 0; i < str[i] != '\0'; i++) {
		nOfSteps++;

		if (str[i] == ch) {
			pos = i;
			break;
		}
	}

	printf("nOfSteps: %d\n", nOfSteps);
	
	return pos;
}

/*
	Hier wird zuerts die string länge gezählt, dannach wird von rechts 
	nach links durch iteriert bis der passende Character gefunden wurde.

	O-Notation
		BestCase     O(n)
		AvrCase      O(n)
		WorstCase    O(n)
*/
int findCharRight(const char* str, char ch) {
	int pos = -1;
	int nOfSteps = 1;

	int strLen = getLengthOfString(str);
	nOfSteps += strLen;

	for (int i = strLen - 1; i >= 0; i--) {
		nOfSteps++;

		if (str[i] == ch) {
			pos = i;
			break;
		}
	}

	printf("nOfSteps: %d\n", nOfSteps);

	return pos;
}

/*
	Hier wird von links nach rechts durch iteriert bis der letzte
	passende Character gefunden wurde.

	O-Notation
		BestCase     O(n)
		AvrCase      O(n)
		WorstCase    O(n)
*/
int findCharRight_2(const char* str, char ch) {
	int pos = -1;
	int nOfSteps = 1;

	for (int i = 0; i < str[i] != '\0'; i++) {
		nOfSteps++;

		if (str[i] == ch) {
			pos = i;
		}
	}

	printf("nOfSteps: %d\n", nOfSteps);

	return pos;
}

/*
	Hier wird zuerst die string länge gezählt, dannach wird der zu prüfende
	Index mit einer random funktion bestimmt, dies wird solange gemacht bis
	der gesuchte Character gefunden ist. Bei 1000 versuchen wird aber abgebrochen
	und eine Fehlermeldung ausgegeben.

	O-Notation
		BestCase     O(1)
		AvrCase      O(n)
		WorstCase    O(∞)
*/
int findCharRandom(const char* str, char ch) {
	int pos = -1;
	int nOfSteps = 1;

	if (str[0] != '\0') {
		int strLen = getLengthOfString(str);
		nOfSteps += strLen;

		pos = rand() % strLen;

		int max = 1000;
		int i = 0;
		while (i < max && str[pos] != ch) {
			pos = rand() % strLen;
			nOfSteps++;

			i++;
		}

		if (pos < 0) {
			printf("char not found!\n\n");
		}
	}

	printf("nOfSteps: %d\n", nOfSteps);

	return pos;
}
// -----------------------------------------------------------------------------------------------------------------------------