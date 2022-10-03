#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    if(argc != 2) {
        return -1;
    }
    int fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        return -1;
    }
    int limit_lines = 10;
    int current = 0;
    char buffer[1];
    while(read(fd, buffer, 1)) {
        write(1, buffer, 1);
        if(buffer[0] == '\n') {
            ++current;
            if(current == limit_lines) {
                break;
            }
        }
    }
}