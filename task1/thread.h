#ifndef THREAD_H
#define THREAD_H

typedef struct {
	int *arr;
	int left;
	int right;
} thread;

int comp(const void *a, const void *b);

void* sort_thread(void* arr);

void merge(int* arr, int left, int mid, int right);

#endif

