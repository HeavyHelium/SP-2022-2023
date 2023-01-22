#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int fd, i, status;
        
	if(fork()) { 
		wait(&status);
        	for(i = 0; i <= 4; ++i) { 
			write(1, "cat\n",4); // write cat to stdout
			execlp("cat", "cat", "ABC", 0); // print contents of ABC to stdout
			write(1, "test1\n", 5); // won't be reached
		}
		// if exec succeeds, then all is well and the loop will be iterated upon exactly once
		// otherwise more tries will be made
	} else { 
		// in child
		close(1); // close its stdout
                fd = open(argv[1], O_RDWR); // open file, it will serve as stdout
        	write (1, "test2\n",5); // write "test2" to file
	}
	write(1, "test3\n", 5); // common part, although it will not be reached in parrent
	// write "test3" to the file with name "argv[0]"
	
	return 0;
}

/// potential order

// stdout: 

// cat
// contents of file ABC
//

// file with name argv[0]: 
// test2test3


















