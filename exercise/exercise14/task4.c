#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char** argv) { 
	if(argc != 3) { 
		return -1;
	} 

	if(fork()) { 
		int wstatus;
		wait(&wstatus);
		printf("Command ended with: %d\n", wstatus);
	} else { 
		int fd_in = open(argv[1], O_RDONLY);
		dup2(fd_in, 0);
		int fd_out = open(argv[2], O_CREAT|O_WRONLY | O_TRUNC, 0777);
		dup2(fd_out, 1);
		dup2(fd_out, 2);
		execlp("grep", "grep", "pts", NULL);
	}
	
	return 0;
}
