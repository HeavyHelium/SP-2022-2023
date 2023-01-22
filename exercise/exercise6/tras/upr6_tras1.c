#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char** argv) { 
	int fd, i = 4, nb1, status;
  	char buf[5];

	if(fork() == 0) { // child
		++i; // i = 5
		printf("Stoinostta na i= %d\n",i); // print 5 to stdout
	} else { // parent
		--i; // i = 3
		exit(0); // and bye
		wait(&status);
         	if(execlp("ls", "ls", "-l", 0) == -1) { 
			i = i + 1; 
		} else { 
			printf("Stoinostta na i= %d\n",i);  
		}
        }
	printf("Stoinostta na i= %d\n",i); // won't be reached from parent
					   // from child will print out "... i = 5..."
}
