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
		FILE* child_f = fopen("child_copy", "w+");
		if (!child_f) {
			printf("Error when opening child_copy\n");
			exit(1);
		}
		fclose(child_f);
		printf("Child\n");
	}
	else {
		FILE* parent_f = fopen("parent_copy", "w+");
		if (!parent_f) {
			printf("Error when opening parent_copy\n");
			exit(1);
		}
		fclose(parent_f);
		printf("Parrent\n");
	}
	return 0;
}
