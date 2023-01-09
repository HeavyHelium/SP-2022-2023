#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int fd, i, status;
    
    if(fork()) {  
        wait(&status);// child executes first
        for(i = 0; i <= 3; i++) { 
            // write "cal\n" to STDOUT
            write(1, "cal\n", 4);
            // this will run successfully
            // the output is a calendar
            execlp("cal", "cal", 0);
            // this line will not be reached
            write(1, "hello1\n", 7); 
        }
    } else { 
        close(1);
        fd = open(argv[1], O_RDWR) ;
        write(1, "hello2\n", 7); // child's STDOUT is the file inputted now
        // writing "hello2\n" to the file
    }
    // child reached this part 
    // and appends "hello\n" to the file
    // parent does not reach this part
    write (1, "hello3\n", 7);

    return 0;
}

/*
STDOUT:
cal
the output of cal, which is a calendar


File: 
hello2
hello3

*/