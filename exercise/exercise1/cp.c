#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>



int main(int argc, char** argv) { 
	if(argc != 3) { 
		return -1;
	}
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0777);

	if(fd1 == -1 || fd2 == -1) { 
		return -1;
	}
	const int buff_size = 100;
	char buffer[buff_size]; 
	int r;
	while(r = read(fd1, buffer, buff_size)) { 
		write(fd2, buffer, r);
	}
	return 0;

}
