#include <stdio.h>
#include <stdlib.h>
#include "str_to_arr.h"

void max_subarray(int* arr, int arr_len) {
	int sub_len = 1;
	int max_len = 1;
	int start = 0;
	int end = 0;
	for (int i = 0; i < arr_len - 1; i++){
		if (arr[i] <= arr[i + 1]){
			sub_len++;
			if (sub_len > max_len){
				max_len = sub_len;
				start = i + 2 - sub_len;
				end = i + 2;
			}
		}
		else {
			sub_len = 1;
		}
	}
	for (int i = start; i < end; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

int main() {
        char *line = NULL;
        size_t len = 0;
        int n_read = getline(&line, &len, stdin);
        if (n_read > 0 && line[n_read-1] == '\n') {
                line[n_read-1] = '\0';
        }
        int len_arr = 0;
        int* arr_dig = str_to_arr(line, &len_arr);
        if (arr_dig) {
                max_subarray(arr_dig, len_arr);
                free(arr_dig);
        }
        free(line);
        return 0;
}
