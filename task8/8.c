#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include "generate_matr.h"

int cur_i = 0;
int cur_j = 0;

/*void signal_handler(int sig) {
	printf("\n");
	printf("i = %d j = %d\n", cur_i, cur_j);
	signal(SIGINT, SIG_DFL);
	return;
}*/

void signal_handler1(int sig) {
	printf("\n");
	printf("i = %d j = %d\n", cur_i, cur_j);
	return;
}


int main() {
	struct sigaction sa;
	sa.sa_handler = signal_handler1;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESETHAND;
	sigaction(SIGINT, &sa, NULL);
	//signal(SIGINT, signal_handler);
	int matr1[100][100];
	int matr2[100][100];
	srand((unsigned int)time(NULL));
	generate_matr(matr1);
	generate_matr(matr2);
	int res[100][100];
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			res[i][j] = 0;
			cur_i = i;
			cur_j = j;
			for (int k = 0; k < 100; k++) {
				res[i][j] += matr1[i][k] * matr2[k][j];
				sleep(0.5);
			}
		}
	}
	return 0;
}
