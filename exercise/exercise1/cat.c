#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



int main() { 
	const int buffer_size = 100;
	char buffer[buffer_size];
	int r = 0;
	while(r = read(0, buffer, buffer_size)) { 
		write(1, buffer, r);
	}
	return 0;	
}
