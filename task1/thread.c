#include <stdlib.h>
#include <pthread.h>
#include "thread.h"

int comp(const void *a, const void *b) {
    	return (*(int*)a - *(int*)b);
}

void* sort_thread(void* arr) {
    	thread *data = (thread*)arr;
    	if (data->left < data->right) {
        	int count = data->right - data->left + 1;
        	qsort(data->arr + data->left, count, sizeof(int), comp);
    	}
    	return NULL;
}

