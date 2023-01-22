#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char** argv) { 
	int fd[200];
	fd[0] = 1;
	for(int i = 1; i < argc; ++i) { 
		if((fd[i] = open(argv[i], O_CREAT | O_WRONLY | O_TRUNC, 0777)) == -1) { 
			return -1;
		}
	}
	const int buffer_size = 100;
	char buffer[buffer_size];
	int r;
	while(r = read(0, buffer, buffer_size)) { 
		for(int i = 0; i < argc; ++i) { 
			write(fd[i], buffer, r);
		}
	
	}
	return 0;
}
