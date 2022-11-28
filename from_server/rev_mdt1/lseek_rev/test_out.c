#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() { 
	int fd = open("42.txt", O_RDONLY, 0777);
	lseek(fd, -1, SEEK_END);
	char buff;
	read(fd, &buff, 1);
	write(1, &buff, 1);


	return 0;
}
