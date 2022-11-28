#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() { 
	int fd1 = open("f1", O_RDONLY);
	int fd2 = open("f1", O_WRONLY);
	if(fd1 == -1 || fd2 == -1) { 
		return -1;
	}
	
	lseek(fd2, -3, SEEK_END);
	write(fd2, "wxyz", 4);
	lseek(fd2, 4, SEEK_SET);
	write(fd2, "12", 2);
	
	int r; 
	char buffer[10];
	while(r = read(fd1, buffer, 10)) { 
		write(1, buffer, r);
	}
	write(1, "\n", 1);

	return 0;
}
