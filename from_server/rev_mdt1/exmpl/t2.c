#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>



int main(int argc, char** argv) {
	if(argc != 3) { 
		printf("Wrong usage!\n");
		exit(-1);
	}	
	
	int fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);

	if(fd1 == -1 || fd2 == -1) { 
		printf("Failed to open file\n");
		exit();
	}

	int pid = fork();

	if(pid < 0) { 
		printf("Fork failed!\n");
		exit(-1);
	}

	if(pid) { 
		int wstatus;
		int chpid = wait(&wstatus);
		int err_file = open("tee_errors", O_CREAT | O_WRONLY | O_APPEND, 0777);
		dup2(err_file, 2);
		close(err_file);

		char buff[30];

		sprintf(buff, "Child finished with status: %d\n", wstatus);
		write(2, buff, strlen(buff));
		
	} else { 
		dup2(fd1, 0);
		dup2(fd2, 2);
		close(fd1);
		close(fd2);i
		execlp("tee", "tee", NULL);
	}
	


	return 0;
}
