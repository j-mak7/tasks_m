#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generate_matr.h"

int main() {
        int matr1[100][100];
        int matr2[100][100];
        srand((unsigned int)time(NULL));
        generate_matr(matr1);
        generate_matr(matr2);
        int res[100][100];
        for (int i = 0; i < 100; i++) {
        	for (int j = 0; j < 100; j++) {
                        res[i][j] = 0;
                        for (int k = 0; k < 100; k++) {
                                res[i][j] += matr1[i][k] * matr2[k][j];
                        }
                        printf("%d ", res[i][j]);
                }
                printf("\n");
        }
        return 0;
}
