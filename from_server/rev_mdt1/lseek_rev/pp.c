#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main() { 
	int fd = open("test_file.txt", O_RDONLY, 0777);
	int pos = lseek(fd, -1, SEEK_END);
	printf("pos: %d\n", pos);
	char buff[1];
	read(fd, buff, 1);
	write(1, buff, 1);


}

