#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>



int main(int argc, char** argv) { 
	if(argc != 4) { 
		return -1;
	}
	char buffer[50];

	for(int i = 1; i < argc; ++i) { 
		if(fork()) { 
			int wstatus;
			int chpid = wait(&wstatus);
						
			sprintf(buffer, "%s with pid %d exited with code %d\n", argv[i], chpid, wstatus);
			write(1, buffer, strlen(buffer));

		} else { 
			return execlp(argv[i], argv[i], NULL);
		}
	}

	return 0;
}
