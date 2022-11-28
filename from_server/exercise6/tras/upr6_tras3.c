#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int pid, status; 
	char c = '0', d = 'b';

	pid = fork();
	if(pid != 0) { // parent 
		c = '2';  
		wait(&status); // wait for child, not that there's any reason to
			       // but output from child will come first
	} else {  // child
		d = 'z'; 
   		write(1, "\n c= ", 5); // STDOUT: "\n c= 0" 
		write(1, &c, 1); 
	}
	write(1, "\n d= ", 5); // from parent STDOUT: d = b
			       // from child STDOUT: d = z   
	write(1, &d, 1); 
}
