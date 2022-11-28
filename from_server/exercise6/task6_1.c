#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>




int main(int argc, char** argv) { 
	if(argc != 2) { 
		return -1;
	}

	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(fd == -1) { 
		return -1;
	}	
	
	const char* str = "Hello\n";
	int str_len = strlen(str); 

	if(fork()) { 
		write(fd, str, str_len);
	} else { 
		write(fd, str, str_len);
	}
	


	return 0;
} 

