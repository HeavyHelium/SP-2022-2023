#include <stdio.h>
#include <fcntl.h>


int main(int argc, const char** argv) { 
    if(argc != 2) { 
        printf("Usage: <command> <filename>\n");
        return -1;
    }

    int source = open(argv[1], O_RDONLY);
    if(source == -1) { 
        printf("Error in opening file\n");
        return -1;
    }

    char buffer[10];

    int read_cnt = 0;

    while(read_cnt = read(source, buffer, 10)) { 
        printf("currently read bytes: %d\n", read_cnt);
    } 
    printf("currently read bytes: %d\n", read_cnt);

    return 0;
}