#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define COM "ps"

int main() { 
    int  i = 2, status;
    if(fork()) {  // parent process runs second
        wait(&status); // status = 0
        --i; // i = 1
        printf("Stoinostta na i = %d;", i); // print to stdout "Stroinostta na i = 1;"
    } else { // child process runs first
        i++; // i = 3
        if(execlp(COM, COM, 0) == -1) { // won't get to the if body 
            i = i + 2; 
            printf("Stoinostta na i = %d;", i);
        }
    }
    // parent process continues here,
    // child process has already exited, 
    // as execlp() has replaced it with ps
    printf("Stoinostta na i = %d;", --i); // print to stdout "Stoinostta na i = 0;"


    return 0;
}

/*
STDOOUT
result of ps, i.e. a log of the processes running on the system
Stoinostta na i = 1;Stoinostta na i = 0;
*/