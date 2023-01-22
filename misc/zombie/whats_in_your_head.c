#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>


int main() { 
    
    if(fork()) { 
        printf("zombie with pid: %d", getpid());
    } else { 
        sleep(100);
    }

    return 0;
}