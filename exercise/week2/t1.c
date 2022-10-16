#include <fcntl.h>
#include <stdio.h>
#include <string.h>



int main() { 
    int source = open("aa", O_RDONLY);

    if(source == -1) { 
        printf("Opening file operation failed\n");
        return -1;
    } 

    char buffer[17];

    for(int i = 5; i > 0; --i) { 
        read(source, buffer, 16);
        buffer[16] = '\0';
        printf("%s", buffer);
    }

    printf("\n");

    close(source);


    return 0;
}