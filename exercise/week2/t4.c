#include <fcntl.h>
#include <stdio.h>


int main(int argc, const char** argv) {

    if(argc != 2) { 
        printf("Usage: <command> <filename>\n");
        return -1;
    }

    int source = open(argv[1], O_RDONLY);

    if(source == -1) { 
        printf("Opening file operation failed\n");
        return -1;
    } 

    int destination = 1;

    char buffer[17];

    for(int i = 8; i > 0; --i) { 
        int amount = read(source, buffer, 16);
        write(destination, buffer, amount);
    }

    printf("\n");

    close(source);

    return 0;
}