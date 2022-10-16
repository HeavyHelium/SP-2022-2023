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
        buffer[amount] = '\n';
        write(destination, buffer, amount + 1);
        execlp("wc", "wc", "-c", argv[1]); // once executed, end of program
    }

    printf("\n");

    close(source);

    return 0;
}