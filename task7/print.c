#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void print_file(const char* filename) {
        int fd = open(filename, O_RDONLY);
        char buf[1];
        int nread;
        while ((nread = read(fd, buf, sizeof(buf))) > 0) {
                printf("%s", buf);
        }
        close(fd);
        return;
}
