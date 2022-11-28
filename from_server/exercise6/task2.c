#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char** argv) { 
	if(argc != 2) { 
		return -1;
	}
	
	int ret = execlp("grp", "grep", "hello", argv[1], NULL);
	printf("Command execution/exec failed with code: %d\n", ret);

	return 0;
}
