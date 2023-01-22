#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



int main(int argc, char** argv) { 
	int ch1, ch2;

	if(ch1 = fork()) { 
		int st1, st2;
		if(ch2 = fork()) { 
			waitpid(ch1, &st1, 0);
			waitpid(ch2, &st2, 0); 
			printf("Command1 ended with: %d\n", st1);
			printf("Command2 ended with: %d\n", st2);
		} else { 
			execlp(argv[1], argv[1], NULL);
			exit(-1);

		}
	} else { 
		execvp(argv[2], argv + 2);
	}


	return 0;
}
