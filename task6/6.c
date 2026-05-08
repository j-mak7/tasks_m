#include <stdio.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Usage: %s <file>\n", argv[0]);
		return 1;
	}
	struct stat s;
	stat(argv[1], &s);
	struct passwd *pw = getpwuid(s.st_uid);
        struct group *gr = getgrgid(s.st_gid);
	printf("File: %s\n", argv[1]);
	printf("Size: %ld\t Blocks: %ld\t IO Block: %ld\t \n", s.st_size, s.st_blocks, s.st_blksize);
	printf("Device: %d,%d\t Inode: %ld\t Links: %ld\n", major(s.st_dev), minor(s.st_dev), s.st_ino, s.st_nlink);
	printf("Access: (%04o/)\tUid: (%5d/%s)\tGid: (%5d/%s)\n", s.st_mode & 0777, s.st_uid, pw->pw_name, s.st_gid, gr->gr_name);
	return 0;
}
