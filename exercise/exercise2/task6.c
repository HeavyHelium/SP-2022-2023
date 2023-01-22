#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>




int main(int argc, char** argv) {
	if(argc != 2) { 
		return -1;
	} 
	int fd = open(argv[1], O_RDONLY);
	if(fd == -1) { 
		return -1;
	}	
	char buffer[17];
	int r;
	
	for(int i = 5; i >= 1; --i) { 
		r = read(fd, buffer, i);
		buffer[r] = '\0';
		printf("%s\n", buffer);
	}
	

	return 0;
}

