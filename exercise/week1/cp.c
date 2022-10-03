#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    const int buff_size = 50;
    if(argc != 3) {
        return -1;
    }
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0777);
    if(fd1 == -1) {
        return -1;
    }
    if(fd2 == -1) {
        return -1;
    }
    char buffer[buff_size];
    int r;
    while(r = read(fd1, buffer, buff_size)) {
        write(fd2, buffer, r);
    }
    return 0;
}
