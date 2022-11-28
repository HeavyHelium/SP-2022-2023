#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main() { 
	int fd = open("file1", O_RDONLY);
	int dfd = dup(fd);

	if(fd == -1) { 
		printf("Error in opening the file\n");
		return -1;
	}
	
	int r;
	int buffer[10];
		
	const char* msg1 = "from fd: ";
	const int len1 = strlen(msg1);
	
	const char* msg2 = "from dupped fd: ";
	const int len2 = strlen(msg2);

	r = read(fd, buffer, 10);
	write(1, msg1, len1);
	write(1, buffer, r);
	write(1, "\n", 1);
	
	r = read(dfd, buffer, 10);
	write(1, msg2, len2);
	write(1, buffer, r);
	write(1, "\n", 1);
		
	close(fd);
	
	r = read(dfd, buffer, 10);
	write(1, msg2, len2);
	write(1, buffer, 10);
	write(1, "\n", 1);

	return 0;
}
