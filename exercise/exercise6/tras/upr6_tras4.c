#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main (int argc, char* argv[]) {  
	int fd, j, nb1,status;
	char buf[5];

	if(fork()) { // parent 
		wait(&status); // wait for child 
		execlp("cat", "cat", argv[1], 0); // show contents of the file given and bye 
        } else {  // child
		j = dup(1); // access to STDOUT
		fd = open(argv[1], O_RDWR); // open given file
	        nb1 = read(0, buf, 7); // read 7 bytes from stdin
	        write(j, buf, nb1); // write those bytes to STDOUT
		nb1 = read(fd, buf, 5); // read 5 bytes from file, i.e. 12345
	        write(1, buf, nb1); // STDOUT: 12345 
                write(fd, "\n", 1); // write linefeed to file
                write(fd, buf, nb1); // write 12345 to file
	        write(j, buf, 3); // write 123 to STDOUT
                close(fd); 
		close(j);	
		exit(0); // goodbye
	}    
}

/*
 * STDOUT: 
 * the read 7 byes 
 * 1234512312345
 * 12345
 *
 *------------------
 *
 * File: 
 * 12345
 * 12345
 *
 * */



