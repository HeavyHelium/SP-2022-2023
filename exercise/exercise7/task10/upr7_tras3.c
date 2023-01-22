#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define CMD "who"

int main() {
    int fd, i = 2, k = 0, status;

    if(fork()) {
	// parent part
	wait(&status); // wait for child to finish
        i--; // i has value 1 here
        k--; // k has value -1 here
	write(1, "exam1\n", 6); // write exam1 to stdout
        printf("I = %d K = %d \n", i, k); // print I = 1 K = -1
    } else {
	// child part
        for(k = 1; k <= 3; k++) {
		write(1, "exam2\n", 6); // write exam2 to stdout
		i = k + i; // i has value 3 here
		printf("I = %d K = %d\n", i, k); // print I = 3 K = 1 
            
        	// execute simple who
        	if((execlp(CMD, CMD, 0)) == -1) // execution will not reach this point
			write(1, "exam3\n", 6);
	
        	// child has exited with code 0
        }

    }
	
    // only parent reaches this point
    // write exam4 to stdout
 	

    write(1, "exam4\n", 6);

    // execute simple ls
    if((execlp("ls", "ls", 0)) == -1) {
    // execution will not reach this point
    	printf("I = %d K = %d\n", i, k);
    } else { // execution will not reach this point
        write(1, "exam5\n", 6);
    }
}

/**
 * STDOUT:
 * exam2 
 * I = 3 K = 1
 * output of who
 * exam1
 * I = 1 K = -1 
 * exam4
 * output of ls 
 *         
 **/	    
