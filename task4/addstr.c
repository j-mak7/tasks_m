#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool find_str_arr(char** arr, int arr_len, char* str) {
	for (int i = 0; i < arr_len; i++) {
		if (strcmp(arr[i], str) == 0) {
			return true;
		}
	}
	return false;
}

void alloc_mem(char*** arr, int* len, int* cap) {
	if (*cap <= *len) {
		*cap *= 2;
		char** tmp = realloc(*arr, *cap * sizeof(char*));
		if (!tmp) {
			return;
		}
		*arr = tmp;
	}
}
