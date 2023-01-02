#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() { 
    int pid, var = 1, status;

    if((pid = fork()) == 0) { // child process runs first
        var += 2; // var = 3
        printf("\n Var = %d", var); // print Var = 3 to stdout
    } else { 
        wait(&status);  // wait for child to finish
        var++ ; // var = 2
        printf("\nVar = %d", var); // print Var = 2 to stdout 
        exit(0); // and exit
    }
    // child process continues here, 
    // parent process has already exited
    --var; // var = 2
    
    printf("\n Var = %d", var); // print Var = 2 to stdout
    return 0;
}

/*
STDOUT: 
Var = 3
Var = 2
Var = 2

*/

