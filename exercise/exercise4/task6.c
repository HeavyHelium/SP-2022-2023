#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char** argv) { 
	if(argc != 2) { 
		printf("Wrong usage!\n");
		return -1;
	}

	const char* str1 = "EXAMPLE";
	const int len1 = strlen(str1);
	
	const char* str2 = "HELLO";
	const int len2 = strlen(str2);

	char buffer[30];

	for(int i = 0; i < 10; ++i) { 
		write(1, str1, len1);
                write(1, "\n", 1);
	}

	int temp = dup(1);
	close(1);

	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	// 1 points to where fd points to now
	
	
	for(int i = 0; i < 10; ++i) { 
		sprintf(buffer, "i=%d\n", i);
		write(1, buffer, strlen(buffer));
	}

	close(fd);
	dup(temp);
	close(temp);

	for(int i = 0; i < 10; ++i) { 
		write(1, str2, len2);
		write(1, "\n", 1);
	}

	return 0;

}
