#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "print.h"
#include "addstr.h"


int main(int argc, char *argv[]) {
	opterr = 0;
	char* elb_arr[] = {"1c+", "2c+", "2c3", "4c", "8c", "16c"};
	char short_arr[4] = {0};
	int short_arr_len = 0;
	struct option long_opt[] = {{"elbrus", 1, 0, 0}, {0, 0, 0, 0}};
	int optidx;
	char** long_arr = calloc(4, sizeof(char*));
	int long_arr_len = 0;
	int capasity = 4;
	int c;
	char** non_opt = calloc(4, sizeof(char*));
	int non_opt_cap = 4;
	char** incor_opt = calloc(4, sizeof(char*));
	int incor_opt_len = 0;
	int incor_opt_cap = 4;
	while ((c = getopt_long(argc, argv, "msct", long_opt, &optidx))!=-1) {
		switch (c) {
			case 'm':
				if (strchr(short_arr, 'm') == NULL) {
					short_arr[short_arr_len] = 'm';
					short_arr_len++;
				}
				break;
			case 'c':
				if (strchr(short_arr, 'c') == NULL) {
					short_arr[short_arr_len] = 'c';
					short_arr_len++;
				}
				break;
			case 's':
				if (strchr(short_arr, 's') == NULL) {
					short_arr[short_arr_len] = 's';
					short_arr_len++;
				}
				break;
			case 't':
				if (strchr(short_arr, 't') == NULL) {
					short_arr[short_arr_len] = 't';
					short_arr_len++;
				}
				break;
			case 0:
				if (!find_str_arr(elb_arr, 6, optarg)) {
					incor_opt[incor_opt_len] = strdup(argv[optind - 1] + 2);
					incor_opt_len++;
					alloc_mem(&incor_opt, &incor_opt_len, &incor_opt_cap);
				}
				char* str = strdup("elbrus=");
				str = realloc(str, 8 + strlen(optarg));
				strcat(str, optarg);
				if (!find_str_arr(long_arr, long_arr_len, str)) {
					long_arr[long_arr_len] = strdup(str);
					long_arr_len++;
					alloc_mem(&long_arr, &long_arr_len, &capasity);
				}
				free(str);
				break;
			case '?' :
				char* ptr = argv[optind - 1];
				if (ptr[0] == '-' && ptr[1] == '-') {
					incor_opt[incor_opt_len] = strdup(ptr + 2);
				}
				else if (ptr[0] == '-') {
					incor_opt[incor_opt_len] = strdup(ptr+1);
				}
				else {
					incor_opt[incor_opt_len] = strdup(ptr);
				}
				incor_opt_len++;
				alloc_mem(&incor_opt, &incor_opt_len, &incor_opt_cap);
				break;
		}
	}
	int non_opt_len = 0;
	for (int i = optind; i < argc; i++) {
		non_opt[non_opt_len] = strdup(argv[i]);
		non_opt_len++;
		alloc_mem(&non_opt, &non_opt_len, &non_opt_cap);
	}
	if (incor_opt_len != 0) {
		printf("Incorrect options: ");
		print_str_arr(incor_opt, incor_opt_len);
		free_str_arr(incor_opt, incor_opt_len);
		free_str_arr(non_opt, non_opt_len);
		free_str_arr(long_arr, long_arr_len);
		return 1;
	}
	printf("Short options: ");
	print_arr(short_arr, short_arr_len);
	printf("Long options: ");
	print_str_arr(long_arr, long_arr_len);
	printf("Non options: ");
	print_str_arr(non_opt, non_opt_len);
	//printf("%d %d %d\n", non_opt_len, incor_opt_len, long_arr_len);
	free_str_arr(non_opt, non_opt_len);
	free_str_arr(long_arr, long_arr_len);
	free_str_arr(incor_opt, incor_opt_len);
	return 0;
}

