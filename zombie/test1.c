#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>



int main() { 
    for(int i = 0; i < 3; ++i) { 
        fork();
    }
    printf("hello\n");


    return 0;
}
/*

            r = c0
      /      |     \
      c1     c2     c3
      / \    /     
      c4 c5  c6
      /
      c7     
*/