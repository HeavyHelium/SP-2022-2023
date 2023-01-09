#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h> 

int main(int argc, char** argv) {
    if(argc != 3) { 
        printf("Wrong usage!\n");
        exit(-1);
    }

    if(fork()) { 
        int wstatus;
        wait(&wstatus);
        printf("command execution ended with: %d\n", wstatus);

    } else { 
        int fd_in = open(argv[1], O_RDONLY);
        int fd_out = open(argv[2], O_WRONLY | 
                                   O_CREAT | 
                                   O_TRUNC, 
                                   0644);
        dup2(fd_out, 1);
        dup2(fd_out, 2);
        
        execlp("grep", "grep", "pts", argv[1]);
        
        exit(-1);
    }


    return 0;
}