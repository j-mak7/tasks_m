#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

int main(int argc, char* argv[]) {
	if (argc < 4) {
		printf("Usage: %s <input> <output> <sort>\n", argv[0]);
		return 1;
	}
	FILE* file = fopen(argv[1], "r");
	if (!file) {
		perror("fopen");
		return 1;
	}
	char* buffer = calloc(1024, sizeof(char));
	fread(buffer, 1, 1024, file);
	char** arr = NULL;
	int count = 0;
	int cap = 0;
	char* token = strtok(buffer, "\n");
	while (token) {
		if (count >= cap) {
			if (cap == 0) {
				cap = 4;
			} else {
				cap = cap * 2;
			}
			arr = realloc(arr, cap * sizeof(char*));
		}
		arr[count] = token;
		count++;
		token = strtok(NULL, "\n");
	}
	/*for (int i = 0; i < count; i++) {
		printf("'%s'", arr[i]);
	}
	printf("\n");*/
	if (strcmp(argv[3], "plain") == 0) {
		qsort(arr, count, sizeof(char* ), plain);
	}
	FILE* output = fopen(argv[2], "w");
	if (!output) {
		perror("fopen");
	}
	for (int i = 0; i < count; i++) {
		fprintf(output, "%s\n", arr[i]);
	}
	free(buffer);
	free(arr);
	fclose(file);
	return 0;
}
