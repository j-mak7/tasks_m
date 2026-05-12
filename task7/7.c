#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t p = fork();
	if(p < 0){
		printf("Error\n");
		exit(1);
	}
	else if (p == 0) {
		printf("Child\n");
	}
	else {
		printf("Parrent\n");
	}
	return 0;
}
