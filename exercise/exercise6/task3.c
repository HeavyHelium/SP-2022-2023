#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char** argv) { 
	if(argc != 2) {
		return -1;
	} 


	if(fork()) { 
		int wstatus;
		int chpid = wait(&wstatus);
		if(!wstatus) { 
			write(1, argv[1], strlen(argv[1]));
			write(1, "\n", 1);
		}
	
	
	} else { 
		return execlp(argv[1], argv[1], NULL);
	}
	

	return 0;
}
