#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main() {
    int fd = open("digits.txt", O_RDWR);
    if(fd == -1) { 
        printf("Opening file failure\n");
        exit(-1);
    }

    lseek(fd, 1, SEEK_SET);

    char buffer[80];

    int r_bytes = read(fd, buffer, 20);
    char temp[30];
    sprintf(temp, "%d", r_bytes);
 
    write(1, buffer, r_bytes);

    return 0;
}