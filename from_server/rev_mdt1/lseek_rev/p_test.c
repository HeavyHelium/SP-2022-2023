#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() { 
	int fd = open("alphabet", O_RDONLY);
	
	char buffer[16];
	int r;
	for(int i = 5; i > 0; --i) { 
		lseek(fd, -3, SEEK_END);
		r = read(fd, buffer, i);
		write(1, buffer, r);
		write(1, " here\n", 1);	
	}


	return 0;
}
