#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char** argv) { 
	int fd, k, status;
	fd = open ( argv[1], O_RDWR) ;
	
	if ( fork() ) { 
		wait(&status);
		dup(fd);
		write ( 1, "who\n", 4);
		execlp ( "who", "who","-u",0); 
		write (fd, "exam1\n",5);
         } else { 
		close(1); dup(fd);
                for ( k=0; k<=3; k++)
                write (1, "exam2\n",6); 
         }
        execlp ( "pwd", "pwd",0);

	return 0;
}

/*
 in file: 
 exam2
 exam2
 exam2
 exam2
 output of pwd, which is the address of the current working directory
 

 stdout:
 who
 output of who, which is the users who are active
 
 * */
