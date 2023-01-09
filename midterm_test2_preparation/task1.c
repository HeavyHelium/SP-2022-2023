#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>


// name of a file, command with options and arguments
int main(int argc, char** argv) { 

	if(fork()) {
		int child1, child2, child3;

		child1 = wait(NULL);
		if(fork()) { 
			child2 = wait(NULL);
			if(fork()) { 
				int wstatus;
				child3 = wait(&wstatus);
				if(wstatus == 0) { 
					printf("child1: %d\nchild2: %d\nchild3: %d\n", child1, child2, child3);
				} 
			
			} else { 
				execvp(argv[2], argv + 2);
				exit(-1);
			}
		} else { 
			execlp("ls", "ls", "/home/KN/SYSPROG", "-l", NULL);
			exit(-1);
		}
	
	} else { 
		execlp("cp", "cp", argv[1], "/home/student/f1", NULL);
		exit(-1);
	}
	
	
	
	
	return 0;
} 
