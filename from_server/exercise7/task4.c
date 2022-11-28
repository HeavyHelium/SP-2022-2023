#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) { 
    if(argc != 3) { 
        printf("Usage: %s <file1> <file2>\n", argv[0]);
    }

    int fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);

    if(fork()) { 
        write(fd1, "hello1\n", 7);

    } else {
        write(fd1, "hello2\n", 7);
    }

    return 0;
}
