#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char** argv) { 
    if(argc != 3) { 
        printf("Usage: %s <file1> <file2>\n", argv[0]);
    }

    int fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);

    if(fork()) { 
        wait(NULL);
        write(fd1, "hello1\n", 7);

    } else {
        int true_stdout = dup(1);
        close(1);
 
        dup(fd2);        
        write(fd1, "hello2\n", 7);
        close(1);
 
        dup(true_stdout);
        exit(-1);
    }

    write(1, "hello3\n", 7);
    write(fd2, "hello4\n", 7);

    return 0;
}