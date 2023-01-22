#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>



int main(int argc, char** argv) { 
    if(argc != 3) { 
        printf("Wrong usage!\n");
        exit(-1);
    }

    char cmd[80];
    int bytes = read(0, cmd, 80);
    cmd[bytes - 1] = '\0';

    int fd = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0777);

    if(fork()) {
        int wstatus; 
        wait(&wstatus);
        char buff[30];
        sprintf(buff, "%d", wstatus);
        write(fd, buff, strlen(buff));
        write(fd, "\n", 1);
        write(fd, cmd, strlen(cmd));
        write(fd, "\n", 1);
        write(fd, argv[1], strlen(argv[1]));

    } else {
        int fd[2];
        pipe(fd); 
        if(fork()) {
            close(0);
            close(fd[1]);
            dup(fd[0]);
            close(fd[0]); 
            execlp(argv[1], argv[1], NULL);
            exit(-1);
        } else { // let child execute first
            close(fd[0]);
            close(1);
            dup(fd[1]);
            close(fd[1]);
            execlp(cmd, cmd, NULL);
            exit(-1);
        }

    }

    return 0;
}