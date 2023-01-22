#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char buffer[30];
enum { Parent = 1, Child = 2, }; 

void perform_operations(int fd, int incr) { 
	int val;
	for(int i = 0; i < 10000; ++i) { 
		lseek(fd, 0, SEEK_SET);
		read(fd, &val, sizeof(int));
		val += incr;
		if(incr == Parent) { 
			printf("Parent: ");
		} else { 
			printf("Child: ");
		}
		printf("val is %d\n", val);
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
	
	lseek(fd, 0, SEEK_SET);
	read(fd, &val, sizeof(int));
	printf("finally, val is: %d\n", val);			
		

	return 0;
}
