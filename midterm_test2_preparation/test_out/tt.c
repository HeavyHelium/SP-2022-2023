#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
	char buffer[16];
	int fd1 = open("ff", O_RDONLY);
	int fd2 = dup(fd1);
	write(1, buffer, read(fd1, buffer, 16));
	write(1, buffer, read(fd2, buffer, 16));
	close(fd1);
	write(1, buffer, read(fd2, buffer, 16));

	return 0;
}
