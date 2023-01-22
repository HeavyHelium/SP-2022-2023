#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>



int main(int argc, char** argv) { 
		
	char buffer[30];
	if(fork()) { 
		int wstatus;
                int chpid = wait(&wstatus);
                if(!wstatus) {
			sprintf(buffer, "Code: %d\n", wstatus);
		        write(1, buffer, strlen(buffer));
                        write(1, "\n", 1);
                } 

	} else { 
		return execvp(argv[1], argv + 1);

	} 


	return 0;
}
