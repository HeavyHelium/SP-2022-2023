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
        if(fork()) { 
        } else { 
            execlp(argv[2], argv[2], NULL);
            exit(-1);
        }
        int succ;
        int wstatus;
        succ = wait(&wstatus);
        if(wstatus) {
            succ = wait(&wstatus);
            if(wstatus) {
                printf("Both commands failed.\n");
                exit(-1);
            }
        } 
        printf("command with pid: %d succeeded.\n", succ); 

    } else { 
        execlp(argv[1], argv[1], NULL); 
        exit(-1);   
    }

    return 0;
}