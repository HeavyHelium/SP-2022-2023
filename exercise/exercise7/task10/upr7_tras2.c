#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define CMD "wc -l $PWD"



int main(int argc, char* argv []) { 
    int fd, i = 2, nb1, status;
    char buf[5];

	if(fork() == 0) {
        // child part
        	++i;
	// i has value 3 here
		exit(0);
	} else { 
	// parent part
		if(execlp(CMD, CMD, 0) == -1) { 
			// execution will reach this point
			--i; // I has value 1 here
			wait(&status);
			printf("Stoinostta na i = %d\n", i); 
		} else { // execution won't reach this point 
			printf("Stoinostta na i = %d\n", i);
		} 
	}
}

/**
 * STDOUT:
 * Stoinostta na i = 1
 *  
 *    
 * */   

	
