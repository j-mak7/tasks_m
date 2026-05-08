#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_to_arr.h"

int* str_to_arr(char* str, int* len) {
	char* word = strtok(str, " ");
	int count_words = 0;
	char** words = calloc(100, sizeof(char*));
	while (word != NULL) {
		if (!is_number(word)) {
			printf("Input does not contain a number!\n");
			free(words);
			return NULL;
		}
		words[count_words] = word;
		count_words++;
		word = strtok(NULL, " ");
	}
	int* arr = calloc(100, sizeof(int));
	for (int i = 0; i < count_words; i++) {
		arr[i] = atoi(words[i]);
		//free(words[i]);
		printf("%d ", arr[i]);
	}
	*len = count_words;
	free(words);
	return arr;
}

