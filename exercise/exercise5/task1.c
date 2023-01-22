#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char** argv) {
	if(argc != 2) { 
		return -1;
	} 

	int fd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if(fd == -1) { 
		return -1;
	}

	char buffer[10];

	while(read(0, buffer, 1)) { 
		if(buffer[0] == '\t') { 
			write(fd, "|->", 3);	
		} else { 
			write(fd, buffer, 1);
		}
	}


	return 0;
}


