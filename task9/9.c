#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	char *line = NULL;
	int len = 0;
	int n_read = getline(&line, &len, stdin);
	if (n_read > 0 && line[n_read-1] == '\n') {
		line[n_read-1] = '\0';
	}
	int len_arr = 0;
	int* arr_dig = str_to_arr(line, &len_arr);
	free(arr_dig);
	free(line);
	return 0;
}
