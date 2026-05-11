#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		write(1, "Error arguments\n", 16);
		return 1;
	}
	int fd1;
	int fd2;
	char arr[1000];
	if (strcmp(argv[1], argv[2]) > 0) {
		int n = read(0, arr, sizeof(arr));
		fd1 = open(argv[1], O_WRONLY);
		write(fd1, arr, n);
		close(fd1);
		fd2 = open(argv[2], O_RDONLY);
		n = read(fd2, arr, sizeof(arr));
		write(1, arr, n);
		close(fd2);
	} else {
		fd2 = open(argv[2], O_RDONLY);
		int n = read(fd2, arr, sizeof(arr));
		write(1, arr, n);
		close(fd2);
		n = read(0, arr, sizeof(arr));
		fd1 = open(argv[1], O_WRONLY);
		write(fd1, arr, n);
		close(fd1);
	}
	return 0;
}
