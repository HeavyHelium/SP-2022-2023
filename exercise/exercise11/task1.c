#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>




int main() { 
	int fd[2];
	pipe(fd);	

	if(fork()) { // parent
			  // parent writes to pipe 
		close(1); // close STDOUT
	        dup(fd[1]); // Make pipe second end to be STDOUT
       	 	close(fd[1]); // close it, it won't be used
        	close(fd[0]); // close pipe read end, it won't be read from
        	execlp("who", "who", NULL); // execute command, 
					    // its output will be stored in pipe file
	} else { 
		close(0);
		dup(fd[0]);
		close(fd[0]);
		close(fd[1]);	
		execlp("wc","wc","-l",NULL);
	}
	return 0;
}
