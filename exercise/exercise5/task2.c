#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int is_digit(char ch) { 
	return ch >= '0' && ch <= '9';
}



int main(int argc, char** argv) { 
	if(argc != 3) { 
		return -1;
	}

	int fd = open(argv[1], O_RDONLY);

	if(fd == -1) { 
		return -1;
	}

	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);

	char buffer1[1];	
	char buffer2[1];	

	int r1, r2;	

	while(1) { 
		r1 = read(fd, buffer1, 1); 
		r2 = read(0, buffer2, 1);
			

		if(r1 && !is_digit(buffer1[0])) { 
			write(fd2, buffer1, 1);
		}
		if(r2 && !is_digit(buffer2[0])) {	
			write(fd2, buffer2, 1);
		}
		if(!r1 || !r2) { 
			break;
		}
	}
	

	return 0;
}
