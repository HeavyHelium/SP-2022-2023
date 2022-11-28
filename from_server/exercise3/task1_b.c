#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main() { 
	int fd1 = open("fff", O_RDONLY);
	int fd2 = open("fff", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	int fd3 = open("fff", O_RDWR);
	
	if(fd1 == -1 || fd2 ==-1 || fd3 == -1) { 
		return -1;
		printf("Here");
	}
	
	char str[] = "Hello";
	int len = strlen(str);
	write(fd3, str, len);

	write(fd2, "worlds", 6);
	char buffer[20];
	
	int r = read(fd1, buffer, 6);
	write(1, buffer, r);
	close(fd2);

	write(fd3, "oops", 4);
	
	r = read(fd1, buffer, 6);

	write(1, buffer, r);
	
	
	write(1, "\n", 1);
	return 0;
}
