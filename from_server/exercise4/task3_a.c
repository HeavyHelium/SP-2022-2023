#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main() { 
	const char* str = "EXAMPLE\n";
	const int len = strlen(str);

	close(1);  
	int fd1 = open("f1", O_WRONLY | O_TRUNC | O_CREAT, 0777);

	for(int i = 0; i < 10; ++i) { 
		write(1, str, len);
	}

	return 0;
}
