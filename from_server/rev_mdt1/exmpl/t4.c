#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char** argv) { 
	if(argc != 3) {
		printf("Wrong usage!\n");
		exit(-1);		
	}

	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0777);

	if(fd1 == -1 || fd2 == -1) { 
		printf("Opening files failed.\n");
		exit(-1);
	}
	
	int pid = fork();

	if(pid == -1) { 
		printf("Forking failed\n");
		exit(-1);
	}
	
	if(pid) { 
		int wstatus;
		int chpid = wait(&wstatus);
		int errs = open("tee_errors", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		
		if(errs == -1) { 
			printf("Failed to open file!\n");
			exit(-1);
		}
		
		dup2(errs, 2);
		close(errs);
		char buffer[30];
		sprintf(buffer, "Child exited with status: %d\n", wstatus);
		write(2, buffer, strlen(buffer));	

		close(fd1);
		close(fd2);			
	} else {
		dup2(fd1, 0);
		close(fd1);
		dup2(fd2, 2);
		close(fd2);
		execlp("tee", "tee", NULL);
		return -1;
	}
	

	
	return 0;
}
