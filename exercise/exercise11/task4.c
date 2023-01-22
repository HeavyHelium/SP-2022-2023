#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char** argv) { 
	int fd[2];
	pipe(fd);
	if(argc != 4) { 
		printf("Wrong usage!\n");
		return -1;
	}

	if(fork()) { // parent executes first command
		     // and writes to pipe1
		close(1);
		dup(fd[1]);
		close(fd[1]);
		execlp(argv[1], argv[1], NULL);		

	} else { 
		int s_fd[2];
		pipe(s_fd);
		if(fork()) { // child reads from pipe1 
			     // writes to pipe2
			close(0);
			dup(fd[0]);
			close(fd[0]);
			close(1);
			dup(s_fd[1]);
			close(s_fd[1]);
			execlp(argv[2], argv[2], NULL);
		} else { // grandchild reads from pipe2 and writes to stdout
			close(0);
			dup(s_fd[0]);
			close(s_fd[0]);
			execlp(argv[3], argv[3], NULL);
		} 

	}



	return 0;
}

/*
c1 writes to pipe1 
c2 reads from pipe1 and writes to pipe2
c3 reads from pipe2 and writes to stdout
*/

