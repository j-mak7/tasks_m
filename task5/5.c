#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
	int fd = open("file.txt", O_RDONLY);
	if (fd == -1) {
		perror("Can’t open file");
	}
	close(fd);
	return 0;
}
