#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>




int main(int argc, char** argv) { 
	if(argc != 2) { 
		return -1;
	}
	int fd = open(argv[1], O_CREAT | O_WRONLY | O_APPEND, 0777);
	if(fd == -1) { 
		return -1;
	}
	int r;
	const int buff_size = 100;
	char buffer[buff_size];
	while(r = read(0, buffer, buff_size)) { 
		write(fd, buffer, r);
	}
	return 0;
}
