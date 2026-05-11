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