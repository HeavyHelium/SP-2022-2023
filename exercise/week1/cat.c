#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    const int buff_size = 50;
    char buffer[buff_size];
    int r;
    while(r = read(0, buffer, buff_size)) {
        write(1, buffer, r);
    }

    return 0;
}