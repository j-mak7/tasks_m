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

void merge(int* arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int leftArr[n1], rightArr[n2];
	for (int i = 0; i < n1; i++) {
		leftArr[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++) {
		rightArr[j] = arr[mid + 1 + j];
	}
	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			i++;
		}
		else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}

