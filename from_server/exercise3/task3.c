#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) { 
	if(argc != 3) { 
		return -1;
	} 
	int beg = atoi(argv[1]);
	
	int fd = open(argv[2], O_RDONLY);
	if(fd == -1) { 
		return -1;
	}	
	
	int i = 1;
	char buffer[10];
	while(read(fd, buffer, 1)) { 
		if(buffer[0] == '\n') { 
			++i;
		}
		if(i >= beg) { 
			write(1, buffer, 1);
		}
	}
	
	return 0;
}
