#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char** argv) { 
	int fd[2];
	pipe(fd);

	if(fork()) { // parent writes
		close(1);
		dup(fd[1]);
		close(fd[1]);
		execlp(argv[1], argv[1], NULL);
	
	} else { // child reads
		close(0);
		dup(fd[0]);
		close(fd[0]);
		close(fd[1]);
		execvp(argv[2], argv + 2);
	}

	return 0;
}
