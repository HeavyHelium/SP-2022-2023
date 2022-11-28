#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int is_digit(char ch) { 
	return ch <= '9' && ch >= 0;
}


int main(int argc, char** argv) { 
	if(argc != 3) { 
		printf("Wrong usage\n");
		exit(-1);
	}

	int fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1) { 
		printf("Failed to open file\n");
		exit(-1);
	}
	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if(fd2 == -1) { 
		printf("Failed to open file\n");
		exit(-1);
	}

	char ch1, ch2;	
	while(read(fd1, &ch1, 1) && read(0, &ch2, 1)) { 
		if(!is_digit(ch1)) { 
			write(fd2, &ch1, 1);
		}
		if(!is_digit(ch2)) { 
			write(fd2, &ch2, 1);
		}	
	}
	close(fd1);
	close(fd2);
	



	return 0;
}

