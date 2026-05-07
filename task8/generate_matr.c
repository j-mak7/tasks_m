#include <stdlib.h>

void generate_matr(int matr[100][100]) {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			matr[i][j] = rand() % 10;
		}
	}
	return;
}
