#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) { 

    int fd, i = 4, nb1, status;
    char buf[5];
    
    if(fork() == 0) {
        // child part
        ++i;
        printf("Stoinostta na i = %d\n", i);
        // i has value 5 here
    } else {
        // parent part
        --i; // i has value 3 here
        exit(0);// parent process exits
        wait(&status);
        
        if(execlp("ls", "ls", "-l", 0) == -1) { 
            i = i + 1;
        } else {
            printf("Stoinostta na i = %d\n", i);
        }
    }
    // Only child reaches this point
    printf("Stoinostta na i = %d\n", i);
}
/**
 *  STDOUT: 
 * Stoinostta na i = 5
 * Stoinostta na i = 5
 * 
 * 
*/