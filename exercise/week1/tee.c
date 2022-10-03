#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv) {
    const int buff_size = 50;
    char buffer[buff_size];

    int dscrptrs[100];
    dscrptrs[0] = 1;
    for(int i = 1; i < argc; ++i) {
        if((dscrptrs[i] = open(argv[i], O_WRONLY | O_TRUNC | O_CREAT, 0777)) == -1) {
            return -1;
        }
    }
    int r;
    while(r = read(0, buffer, buff_size)) {
        for(int i = 0; i < argc; ++i) {
            write(dscrptrs[i], buffer, r);
        }
    }

    return 0;
}