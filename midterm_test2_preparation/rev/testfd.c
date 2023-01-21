#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>




int main() { 
	int fd = open("ff", O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if(fork()) { 
		wait(NULL);
		write(fd, "parent", 7);
	} else { 
		write(fd, "child", 5);
		close(fd);
	}
	
	printf("fd: %d\n", fd);
	return 0;
}
