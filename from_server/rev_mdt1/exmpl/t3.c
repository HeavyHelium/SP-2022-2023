#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>



int main() { 
	execlp("ls", "ls", "-lh", NULL);


	return 0;
}
