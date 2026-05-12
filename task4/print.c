#include <stdlib.h>
#include "print.h"

void print_arr(char* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("'%c'", arr[i]);
	}
	printf("\n");
}

void print_str_arr(char** arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("'%s'", arr[i]);
	}
	printf("\n");
}

void free_str_arr(char** arr, int len) {
	for (int i = 0; i < len; i++) {
		free(arr[i]);
	}
	free(arr);
}
