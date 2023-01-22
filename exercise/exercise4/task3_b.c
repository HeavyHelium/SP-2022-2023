#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main() { 
	const char* str = "EXAMPLE\n";
	const int len = strlen(str);
  
	int fd1 = open("f1", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	close(1);
	dup(fd1); // first free is 1 
		  // and 1 is set to point to where fd1 points to 

	for(int i = 0; i < 10; ++i) { 
		write(1, str, len);
	}

	return 0;
}
