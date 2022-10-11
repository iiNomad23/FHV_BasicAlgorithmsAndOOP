/*
	pointerManipulations
	tokenizer
	copyCharStrDynMem

	Author: Marco Prescher
	Created on: 17.03.2021
*/

#include <stdio.h>


#define FALSE 0
#define TRUE (!(FALSE))

#define MAX_LENGTH_TEXT 100
#define MAX_LENGTH_ARRS (MAX_LENGTH_TEXT / 2) + 1

struct indexArrsOfStr {
	int indices[MAX_LENGTH_ARRS];
	char* addresses[MAX_LENGTH_ARRS];
	int wordCount;
} indexArrsOfStr;

// forward declarations ---------------------------------------------------------------------------------------------------------
int getLengthOfString(const char* str);
int getLengthOfAWordFromString(char* str, int pos);
int countWords(const char str[]);

// pointerManipulations ------------------------------------------
void pointerManipulations(int i, int k);

// tokenizer -----------------------------------------------------
struct indexArrsOfStr tokenizer(char str[], struct indexArrsOfStr);
void setIndicesOfStr(char str[], int indices[]);
void setAddressOfStr(char str[], char* addresses[]);

// copyCharStrDynMem ---------------------------------------------
char* strDuplicate(const char* pSrc);
// -----------------------------------------------------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
	int test_pointerManipulations = 0;
	int test_tokenizer = 1;
	int test_copyCharStrDynMem = 0;

	int success = TRUE;
	int errCnt = 0;

	if (test_pointerManipulations) {
		printf("\n\n#### pointerManipulations #################################################################\n\n");
		
		pointerManipulations(1234, 5678);
	}
	if (test_tokenizer) {
		printf("\n\n#### tokenizer ############################################################################\n\n");

		char str[MAX_LENGTH_TEXT] = "Dies ist ein Probetext";
		//char str[MAX_LENGTH_TEXT] = "Dies";
		//char str[MAX_LENGTH_TEXT] = "  Dies";
		//char str[MAX_LENGTH_TEXT] = "  Dies  ";
		//char str[MAX_LENGTH_TEXT] = " ";
		//char str[MAX_LENGTH_TEXT] = "";

		struct indexArrsOfStr indexes = { {0}, { NULL }, 0 };
		indexes = tokenizer(str, indexes);

		for (int i = 0; i < indexes.wordCount; i++) {
			printf("%d\t\t", indexes.indices[i]);
		}

		printf("\n");

		for (int i = 0; i < indexes.wordCount; i++) {
			printf("0x%p\t", indexes.addresses[i]);
		}
	}
	if (test_copyCharStrDynMem) {
		printf("\n\n#### copyCharStrDynMem ####################################################################\n\n");

		char* str = strDuplicate("Dies ist ein Probetext");
		//char* str = strDuplicate("Dies");
		//char* str = strDuplicate("  Dies");
		//char* str = strDuplicate("  Dies  ");
		//char* str = strDuplicate(" ");
		//char* str = strDuplicate("");
		
		free(str);
		str = NULL;
	}

	printf("\n\n\nTest finished with %d error(s)", (success == TRUE ? 0 : errCnt));

	// just to make it more beautiful ------------------------------------------------------------------------------------------
	printf("\n###########################################################################################\n\n");
	// -------------------------------------------------------------------------------------------------------------------------

	return 0;
}

// function definitions --------------------------------------------------------------------------------------------------------
int getLengthOfString(const char str[]) {
	int i = 0;

	while (str[i] != '\0') {
		i++;
	}

	return i;
}
int getLengthOfAWordFromString(char str[], int pos) {
	int length = 0;

	int i = pos;
	while (str[pos] != '\0' && str[pos] != ' ' && str[pos] != '.') {
		length++;
		pos++;
		i++;
	}

	return length;
};
int countWords(const char str[]) {
	int wordCnt = 0;
	int wordEnd = 0;
	int inWord = 0;

	for (int i = 0; i < str[i] != '\0'; i++) {
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r') {
			if (inWord) {
				inWord = 0;
				wordCnt++;
			}
		}
		else {
			inWord = 1;
		}
	}

	if (inWord) {
		wordCnt++;
	}

	return wordCnt;
}

// pointerManipulations ------------------------------------------
void pointerManipulations(int i, int k) {
	int* pl = &i;

	printf("Adresse pl = %p\tWert von pl = %d\tWert von i = %d\tWert von k = %d\n", pl, *pl, i, k);

	*pl = 2323;
	printf("Adresse pl = %p\tWert von pl = %d\tWert von i = %d\tWert von k = %d\n", pl, *pl, i, k);

	(*pl)++;
	printf("Adresse pl = %p\tWert von pl = %d\tWert von i = %d\tWert von k = %d\n", pl, *pl, i, k);

	pl = &k;
	printf("Adresse pl = %p\tWert von pl = %d\tWert von i = %d\tWert von k = %d\n", pl, *pl, i, k);

	return 0;
}

// tokenizer -----------------------------------------------------
struct indexArrsOfStr tokenizer(char str[], struct indexArrsOfStr indexes) {
	indexes.wordCount = countWords(str);

	setIndicesOfStr(str, indexes.indices);
	setAddressOfStr(str, indexes.addresses);

	return indexes;
}

void setIndicesOfStr(char str[], int indices[]) {
	int i = 0;
	int pos = 0;

	while (str[pos] != '\0') {
		indices[i] = pos;

		pos += getLengthOfAWordFromString(str, pos) + 1;
		i++;
	}
}
void setAddressOfStr(char str[], char* addresses[]) {
	int i = 0;
	int pos = 0;

	while (str[pos] != '\0') {
		addresses[i] = &str[pos];

		pos += getLengthOfAWordFromString(str, pos) + 1;
		i++;
	}
}

// copyCharStrDynMem ---------------------------------------------
char* strDuplicate(const char* pSrc) {
	int strLen = getLengthOfString(pSrc);
	char* pCopy = malloc((strLen + 1) * sizeof(char)); // +1 because we want to set the '\0' as well

	if (pCopy != NULL) {
		int i = 0;

		while (i < strLen) {
			pCopy[i] = pSrc[i];
			i++;
		}

		pCopy[i] = '\0';

		printf("%s", pCopy);
	}
	else {
		printf("No more free memory, duplicate cancelled!");
	}

	return pCopy;
}
// -----------------------------------------------------------------------------------------------------------------------------