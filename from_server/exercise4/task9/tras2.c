#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/// fileA: 123456789

int main() { 
	int fd, j, nb1;
	char buf[5];
		
	// save where true standard output is
	j = dup(1);
	// open file
	fd = open("fileA", O_RDWR);

	// read 4 bytes from standard input	
	nb1 = read(0, buf, 4);

	// write them to standard output 
	write(j, buf, nb1);

	// read 5 bytes from fileA
	nb1 = read(fd, buf, 5);
	// write them to stdout
	write(1, buf, nb1);

	// write those bytes to file
	write(fd, buf, nb1);
	// write to standard output 123
	write(j, buf, 3);
	
	// close file
	close(fd); 
	// close dupped stdout
	close(j);
	// write a new line to stdout
	write(1,"\n", 1);
	// show content of fileA to stdout
	execlp("cat", "cat", "fileA", 0);
}

/*
 STDOUT: 
4 bytes from stdin12345123 

fileA: 
1234512345

content of fileA

 

 
 */
