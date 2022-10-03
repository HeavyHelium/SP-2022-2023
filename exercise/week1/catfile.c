#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    if(argc != 2) {
        return -1;
    }
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    char buff[50];
    int r;
    while(r = read(0, buff, 50)) {
        write(fd, buff, r);
    }
    return 0;
}