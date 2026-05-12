#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "copy.h"

int main(int argc, char* argv[]){
	if (argc < 2) {
		printf("Usage: %s <name_file_to_copy>\n", argv[0]);
		return 1;
	}
	int copy_f = open(argv[1], O_RDONLY);
	if (copy_f < 0) {
		printf("Error when opening %s\n", argv[1]);
		return 1;
	}
	pid_t p = fork();
	if(p < 0){
		printf("Error\n");
		exit(1);
	}
	else if (p == 0) {
		open_copy("child_copy", copy_f);
		printf("CHild\n");
		exit(0);
	}
	else {
		wait(NULL);
		lseek(copy_f, 0, SEEK_SET);
		open_copy("parent_copy", copy_f);
		printf("Parrent\n");
	}
	return 0;
}
