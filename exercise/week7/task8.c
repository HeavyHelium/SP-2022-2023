#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <unistd.h>



int main(int argc, char** argv) { 
    char buffer[30];

    if(argc != 3) { 
        printf("Usage: %s <command1> <command2>\n", argv[0]);
    }

    if(fork()) {
        int wstatus; 
        int child_pid = wait(&wstatus);
        if(wstatus) {
            exit(-1);
        }
        execlp(argv[2], argv[2], NULL);

    } else { 
        int res = execlp(argv[1], argv[1], NULL);
        sprintf(buffer, "child exited with code: %d\n", res); 
        write(1, buffer, strlen(buffer));
        exit(-1);   
    }




    return 0;
}