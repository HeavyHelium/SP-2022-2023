#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>




int main() { 
	int fd = open("aa", O_RDONLY);
	if(fd == -1) { 
		return -1;
	}	
	char buffer[17];
	int r;
	
	for(int i = 5; i >= 1; --i) { 
		lseek(fd, -3, SEEK_END);
		r = read(fd, buffer, i);
		buffer[r] = '\0';
		printf("%s\n", buffer);
	}
	

	return 0;
}

