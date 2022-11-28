#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() { 
	const char* str1 = "EXAMPLE";
	const int len1 = strlen(str1);
	
	const char* str2 = "HELLO";
	const int len2 = strlen(str2);

	char buffer[30];

	for(int i = 0; i < 10; ++i) { 
		write(1, str1, len1);
		write(1, "\n", 1);
		sprintf(buffer, "i=%d\n", i);
		write(1, buffer, strlen(buffer));
		write(1, str2, len2);
		write(1, "\n", 1);

	}

	return 0;
}
