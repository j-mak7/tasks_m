#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void open_copy(const char* new_file, int copy_fd) {
	int parent_f = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (parent_f < 0) {
		printf("Error when opening parent_copy\n");
		exit(1);
	}
	int nread = 0;
	char buf[1];
	while ((nread = read(copy_fd, buf, sizeof(buf))) > 0) {
		write(parent_f, buf, nread);
	}
	close(parent_f);
	return;
}
