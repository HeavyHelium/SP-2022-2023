#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



int main() {
    char buffer[30];

    if(fork()) {
    } else {
        sprintf(buffer, "pid: %d, parent pid: %d\n", getpid(), getppid());
        write(1, buffer, strlen(buffer));

        if(fork()) { 
        } else { 
            sprintf(buffer, "pid: %d, parent pid: %d\n", getpid(), getppid());
            write(1, buffer, strlen(buffer));
        }
    }

    return 0;   
}