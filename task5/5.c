#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int fd = open("file.txt", O_RDONLY);
	if (fd == -1) {
		perror("Can’t open file");
		printf("Errno = %s\n", strerrorname_np(errno));
		printf("sys_errlist: %s\n", strerror(errno));
		exit(errno);
	}
	close(fd);
	return 0;
}
