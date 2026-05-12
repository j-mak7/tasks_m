#ifndef ADDSTR_H
#define ADDSTR_H

#include <stdbool.h>
#include <stdlib.h>

bool find_str_arr(char** arr, int arr_len, char* str);

void alloc_mem(char*** arr, int* len, int* cap);

#endif
