#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>



int main(int argc, char** argv) { 
	char buffer[80];
	int fd[2];

	char cmd[80];
	int r_bytes = read(1, cmd, 80);
	cmd[r_bytes - 1] = '\0';
	
	int status;
	if(fork()) { 
		wait(&status);
		write(1, "Status: ", 8);
		sprintf(buffer, "%d", status);
		write(1, buffer, strlen(buffer));
		write(1, "\n", 1);
	
		int file = open(argv[2], O_WRONLY | 
					 O_TRUNC  | 
					 O_CREAT  | 
					 O_APPEND, 0666);
	
		write(file, cmd, strlen(cmd));
		write(file, "\n", 1);
		write(file, argv[1], strlen(argv[1]));
		write(file, "\n", 1);

		close(file);
	} else {
		pipe(fd);
		if(fork()) { 
			close(fd[1]); // close write end of pipe
			dup2(fd[0], 0); // redirect stdin to pipe
			execlp(argv[1], argv[1], NULL);
			exit(-1);
		} else { 
			close(fd[0]); // close read end of pipe
			dup2(fd[1], 1); // redirect stdout to pipe
			execlp(cmd, cmd, NULL);
			exit(-1);
		}
	}

	return 0;
}

