#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
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
	if (count > 1) {
		qsort(arr, count, sizeof(int), comp);
	}
	for (int i = 0; i < count; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}
