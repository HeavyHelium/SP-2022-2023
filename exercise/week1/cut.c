#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char** argv) {
    if(argc != 2) {
        return -1;
    }
    int fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        return -1;
    }
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int i = 0;

    char buff[1];

    while(read(fd, buff, 1)) {
        ++i;
        if(buff[0] == '\n') {
            i = 0;
            write(1, buff, 1);
        }
        if(i <= m && i >= n ) {
            write(1, buff, 1);
        }
    }

    return 0;
}