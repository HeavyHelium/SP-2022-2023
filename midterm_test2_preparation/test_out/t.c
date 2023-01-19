#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main() {
	int fd = open("ff", O_RDONLY);
	char buffer[50];

	if(fork()) { 
		int r = read(fd, buffer, 10);
		write(1, buffer, r);
		
	} else { 
		int r = read(fd, buffer, 10);
                write(1, buffer, r);
		exit(0);
	}


	return 0;
}
