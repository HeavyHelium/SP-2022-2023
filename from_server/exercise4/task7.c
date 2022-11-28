#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>



int main(int argc, char** argv) { 
	if(argc != 3) { 
		printf("Wrong usage!\n");
		return -1;
	}

	close(0);
	int fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1) { 
		printf("Failed to open first file\n");
		return -1;
	}
	
	close(1);
	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(fd2 == -1) { 
		printf("Failed to open second file\n");
		return -1;
	}

	char buffer[100];
	int r;

	while(r = read(0, buffer, 100)) { 
		write(1, buffer, r);
	}	


	return 0;
}

