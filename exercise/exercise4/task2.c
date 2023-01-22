#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main() { 
	const char* str = "EXAMPLE\n";
	const int len = strlen(str);

	for(int i = 0; i < 10; ++i) { 
		write(1, str, len);
	}

	return 0;
}
