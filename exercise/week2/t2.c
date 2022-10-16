#include <fcntl.h>
#include <stdio.h>


int main() { 
    int source = open("aa", O_RDONLY);
    int destination = 1;

    if(source == -1) { 
        printf("Opening file operation failed\n");
        return -1;
    } 

    char buffer[17];

    for(int i = 5; i > 0; --i) { 
        int amount = read(source, buffer, 16);
        write(destination, buffer, amount);
    }

    printf("\n");

    close(source);

    return 0;
}