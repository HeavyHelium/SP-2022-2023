#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() { 
    char buffer[30];

    if(fork()) { 
    } else { 
        int pid = getpid();
        int ppid = getppid();
        sprintf(buffer, "pid: %d\nparent pid: %d\n", pid, ppid);
        write(1, buffer, strlen(buffer));
    }


    if(fork()) { 
    } else { 
        int pid = getpid();
        int ppid = getppid();
        sprintf(buffer, "pid: %d\nparent pid: %d\n", pid, ppid);
        write(1, buffer, strlen(buffer));

    }

    


    return 0;
} 