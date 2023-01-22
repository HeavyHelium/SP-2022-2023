#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char buffer[30];

void perform_operations(int fd, int incr) { 
	for(int i = 0; i < 1000; ++i) {
		int val; 
		lseek(fd, 0, SEEK_SET);
		read(fd, &val, sizeof(int));
		val += incr;
		sprintf(buffer, "val is %d\n", val);
		write(1, buffer, strlen(buffer));
		lseek(fd, 0, SEEK_SET);
		write(fd, &val, sizeof(int));
	}
}

int main() { 
	int fd = open("ff", O_CREAT | O_TRUNC | O_RDWR, 0777);
	int oupt = open("output.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if(fd == -1) { 
		return -1;
	}
	int val = 0;
	write(fd, &val, sizeof(int));
	int temp = dup(1);
	dup2(oupt, 1);
	
	if(fork()) { 
		perform_operations(fd, 1);		
	} else { 
		perform_operations(fd, 2);
	}	  
	dup2(temp, 1);
	lseek(fd, 0, SEEK_SET);
	read(fd, &val, sizeof(int));
	sprintf(buffer, "finally, val is: %d\n", val);
	write(1, buffer, strlen(buffer));			
	
	
	

	return 0;
}

