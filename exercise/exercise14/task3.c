#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
	int fd, i, status;
        if(fork()) { 
		wait(&status); // child executes first
		for(i = 0; i <= 3; i++) { 
			write(1, "cal\n", 4);
			execlp ( "cal", "cal", 0); // won't be reached by parent
			write ( 1, "hello1\n", 6); }
         } else { 
		close(1); // redicrect output to file
                fd = open ( argv[1], O_RDWR) ;
                write (1, "hello2\n", 6);
	 } 
	// only parent reaches this part
	 write (1, "hello3\n",6);
}
/*
STDOUT: 
cal
output of cal, which is a calendar	


In file: 
hello2hello3
 

 *
 * */

