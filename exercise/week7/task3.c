#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main() { 
    fork();
    fork();
    fork();
    
    printf("Hello there!\n");
    return 0;
}


/*  
    a has b as child
    b has c as child
    c has e as child
    b has d as child
    a has f as child
    f has g as child
    a has h as child
    hence, 8 processes in total. including a.

    Or, more generally, 2^n processes, where n is the number of forks.
*/