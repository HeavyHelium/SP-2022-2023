#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char** argv) { 
	if(argc != 2) { 
		return -1;
	}
	
	execlp("grep", "grep", "hello", argv[1], NULL);


	return 0;
}
