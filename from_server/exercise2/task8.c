#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>




int main() { 
	int fd = open("test_file.txt", O_RDONLY);
	if(fd == -1) { 
		return -1;
	}	
	char buffer[17];
	int r;
	
	do { 
		r = read(fd, buffer, 10);
		printf("%d\n", r);
	} while(r);
	

	return 0;
}

