#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char** argv) { 
	if(argc != 2) { 
		return -1;
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd == -1) { 
		return -1;
	}
	int j = 0; // number of read lines
	
	const int line_limit = 10;	

	char buffer[1];
	
	while(read(fd, buffer, 1)) { 
		write(1, buffer, 1);
		if(buffer[0] == '\n') { 
			++j;
		}
		if(j == line_limit) { 
			break;	
		}
	}	

	return 0;	
}
