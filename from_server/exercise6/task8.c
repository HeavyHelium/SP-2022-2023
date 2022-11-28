#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>




int main(int argc, char** argv) { 
	if(argc != 3) { 
		return -1;
	}

	int fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);		
		
	
	
	if(fd1 == -1 || fd2 == -1) { 
		return -1;
	}	
	
	const char* str = "Hello\n";
	int str_len = strlen(str); 

	if(fork()) { 
		write(fd1, str, str_len);
	} else { 
		close(1);
		dup(fd2);
		write(1, str, str_len);
	}
	


	return 0;
} 

