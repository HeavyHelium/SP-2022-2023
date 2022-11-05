#include <string.h>


int main() { 
	int fd1 = open("fff", O_RDONLY);
	int fd2 = open("fff", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	int fd3 = open("fff", O_RDWR);
	
	if(fd1 == -1 || fd2 ==-1 || fd3 == -1) { 
		return -1;
		printf("Here");
	}
	
	char str[] = "Hello world";
	int len = strlen(str);
	write(fd2, str, len);

	char buffer[20];
	
	int r = read(fd3, buffer, 6);
	write(1, buffer, r);

	r  = read(fd1, buffer, 5);
	
	write(fd3, "chil", 4);


	write(1, buffer, r);
	

	write(fd2, "!!!", 3);
	
	r = read(fd1, buffer, 9);
	write(1, buffer, r);
	
	write(1, "\n", 1);	
	

	return 0;
}

