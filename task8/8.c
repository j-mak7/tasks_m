#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <getopt.h>
#include "generate_matr.h"

int cur_i = 0;
int cur_j = 0;

void signal_handler(int sig) {
        printf("\n");
        printf("i = %d j = %d\n", cur_i, cur_j);
        signal(SIGINT, SIG_DFL);
        return;
}

void signal_handler1(int sig) {
        printf("\n");
        printf("i = %d j = %d\n", cur_i, cur_j);
        return;
}


int main(int argc, char* argv[]) {
        bool is_sigaction = false;
        struct option options[] = {
                {"signal", 0, 0, 'n'},
                {"sigaction", 0, 0, 'a'},
                {0, 0, 0, 0}
        };
        int opt;
        while ((opt = getopt_long(argc, argv, "", options, NULL)) != -1) {
                switch (opt) {
                        case 'n':
                                is_sigaction = false;
                                break;
                        case 'a':
                                is_sigaction = true;
                                break;
                        default:
                                printf("Usage: %s [--signal | --sigaction]\n", argv[0]);
                                return 1;
                }
        }
        if (is_sigaction) {
                struct sigaction sa;
                sa.sa_handler = signal_handler1;
                sigemptyset(&sa.sa_mask);
                sa.sa_flags = SA_RESETHAND;
                sigaction(SIGINT, &sa, NULL);
        }
        else {
                signal(SIGINT, signal_handler);
        }
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
