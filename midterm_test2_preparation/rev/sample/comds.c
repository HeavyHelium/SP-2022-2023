#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>



int main(int argc, char** argv) { 
    if(argv != 3) { 
        printf("Wrong usage\n");
        exit(-1);
    }
    int ch1, ch2;    
    int wstatus1, wstatus2;
    if(ch1 = fork()) {
        if(ch2 = fork()) { 
            waitpid(ch1, &wstatus1, 0);
            waitpid(ch2, &wstatus2, 0);
            printf("Child1: %d\n Child2: %d\n", ch1, ch2);
        } else { 
            execlp(argv[1], argv[1], NULL);
            exit(-1);
        }
    } else { 
        execvp(argv[2], argv + 2);
        exit(-1);
    }

    return 0;
}