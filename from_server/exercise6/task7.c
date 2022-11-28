#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


int main(int argc, char** argv) { 
	if(argc != 2) { 
		return -1;
	}  

	int fd1 = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	int fd2 = open(argv[1], O_RDONLY);	

	if(fd1 == -1 || fd2 == -1) { 
		return -1;
	}

		
	const char* str = "Hello\n";
	const int str_len = strlen(str);

	if(fork()) {
		int wstatus;
		int chpid = wait(&wstatus); 
		char buffer[10];		
		int r = read(fd2, buffer, str_len);
			
		for(int i = 0; i < r; ++i) { 
			write(0, &buffer[i], 1);
			write(0, " ", 1);
		}

	} else { 
		write(fd1, str, str_len);
	} 

	

	return 0;

}
