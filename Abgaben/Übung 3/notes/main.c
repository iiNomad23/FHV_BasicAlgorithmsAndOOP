#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv) {
	const char* path = "C:\\Users\\Jeremias\\source\\repos\\Files1\\Files1\\file.txt";

	FILE* file = NULL;
	errno_t err = fopen_s(&file, path, "r");
	if (file == NULL) {
		printf("fopen error %d", err);
		return;
	}

	int occurrences[10] = { 0 };

	while (1) {
		int c = fgetc(file);
		if (c == EOF) {
			fclose(file);
			break;
		}

		if ('0' <= c && c <= '9') {
			occurrences[c - '0']++;
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("%d x %3d\n", i, occurrences[i]);
	}

}