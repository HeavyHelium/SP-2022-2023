#include <stdio.h>
#include <unistd.h>

const int msg_size = 16;
const char* msg1 = "hello world #1";
const char* msg2 = "hello world #2";
const char* msg3 = "hello world #3";

int main() { 
    char inbuff[msg_size];
    int p[2];

    if(pipe(p) < 0) { 
        return 1;
    }

    write(p[1], msg1, msg_size);
    write(p[1], msg2, msg_size);
    write(p[1], msg3, msg_size);

    for(int i = 0; i < 3; ++i) { 
        read(p[0], inbuff, msg_size);
        printf("% s\n", inbuff);
    }

    return 0;
}