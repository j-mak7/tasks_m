#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "thread.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <number_of_threads>\n", argv[0]);
		return 1;
	}
	int count_thr = atoi(argv[1]);
		if (count_thr <= 0) {
		printf("Number of threads must be a positive integer.\n");
		return 1;
	}
	int capacity = 1;
	int count = 0;
	int *arr = malloc(capacity * sizeof(int));
	while (scanf("%d", &arr[count]) == 1) {
		count++;
		if (count >= capacity) {
			capacity *= 2;
			arr = realloc(arr, capacity * sizeof(int));
		}
	}
	if (count_thr > count) {
		count_thr = count;
	}
	pthread_t *threads = malloc(count_thr * sizeof(pthread_t));
	thread *thread_data = malloc(count_thr * sizeof(thread));
	int size_subarr = count / count_thr;
	int ost = count % count_thr;
	thread_data[0].left = 0;
	int left = 0;
	for (int i = 0; i < count_thr; i++) {
		int real_size_subarr = size_subarr;
		if (i < ost) {
			real_size_subarr += 1;
		}
		thread_data[i].left = left;
		thread_data[i].right = left + real_size_subarr - 1;
		thread_data[i].arr = arr;
		left += real_size_subarr;
		pthread_create(&threads[i], NULL, sort_thread, &thread_data[i]);
	}
	for (int i = 0; i < count_thr; i++) {
		pthread_join(threads[i], NULL);
	}
	for (int i = 0; i < count; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	free(threads);
	free(thread_data);
	return 0;
}