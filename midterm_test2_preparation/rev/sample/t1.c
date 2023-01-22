#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>



int main(int argc, char** argv) { 
    if(argc != 2) { 
        printf("Wrong usage!\n");
        exit(-1);
    }

    int fdd = open(argv[1], O_CREAT | 
                           O_TRUNC | 
                           O_WRONLY, 0777);
    if(fdd == -1) { 
        printf("File opening failure\n");
        exit(-1);
    }

    if(fork()) { 
        wait(NULL);
        execlp("mv", "mv", argv[1], "res", NULL);
        exit(-1);

    } else {
        int fd[2];
        pipe(fd);

        if(fork()) { 
            close(0);
            dup(fd[0]);
            close(fd[1]);
            close(fd[0]);
            close(1);
            dup(fdd);
            execlp("grep", "grep", "vim", NULL);
            exit(-1);

        } else { 
            close(1);
            dup(fd[1]);
            close(fd[1]);
            close(fd[0]);
            execlp("ps", "ps", "aux", NULL);
            exit(-1);
        }

    }


    return 0;
}
