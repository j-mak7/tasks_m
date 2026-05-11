#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "print.h"

int main(int argc, char *argv[]) {
	const char* elb_arr[] = {"1c+", "2c+", "2c3", "4c", "8c", "16c"};
	char short_arr[4];
	int short_arr_len = 0;
	struct option long_opt[] = {{"elbrus", 1, 0, 0}, {0, 0, 0, 0}};
	int optidx;
	char** long_arr = malloc(4 * sizeof(char*));
	int long_arr_len = 0;
	int capasity = 4;
	int c;
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
				if (capasity <= long_arr_len) {
					capasity *= 2;
					long_arr = realloc(long_arr, capasity);
				}
				long_arr[long_arr_len] = strdup("elbrus=");
				long_arr[long_arr_len] = realloc(long_arr[long_arr_len], 8 + strlen(optarg)); 
				strcat(long_arr[long_arr_len], optarg);
				//strcpy(long_arr + long_arr_len, "elbrus=");
				long_arr_len += 1;
				//strcpy(long_arr + long_arr_len, optarg);
				//long_arr_len += strlen(optarg);
				break;
			case '?' :
				printf("Unknown option: %c\n", optopt);
				break;
			}
	}
	printf("Short options: ");
	print_arr(short_arr, short_arr_len);
	printf("Long options: ");
	print_str_arr(long_arr, long_arr_len);
	free_str_arr(long_arr, long_arr_len);
	return 0;
}
