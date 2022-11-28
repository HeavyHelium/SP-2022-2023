#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>




int main() { 
	int fd = open("aa", O_RDONLY);
	if(fd == -1) { 
		return -1;
	}	
	char buffer[18];
	int r;
	
	for(int i = 5; i >= 1; --i) { 
		r = read(fd, buffer, i);
		buffer[r] = '\n';
		write(1, buffer, r + 1);
	}
	

	return 0;
}

