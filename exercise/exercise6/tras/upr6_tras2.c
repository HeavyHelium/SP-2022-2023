#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define CMD "wc -l $PWD"

int main(int argc, char* argv[]) { 
	int fd, i = 2, nb1, status;
	char buf[5];
	if(fork() == 0) { // child
		++i;  
		exit(0);
	} else { // parent
		if(execlp(CMD, CMD, 0) == -1) { // command will not be executed successfully
			wait(&status);
                	printf("Stoinostta na i= %d\n",i);
               } else { 
			printf("Stoinostta na i= %d\n",i);  // "...i = 2 ... "
		}
	}
}

/// STDOUT: "Stoinostta na i= 2\n"
