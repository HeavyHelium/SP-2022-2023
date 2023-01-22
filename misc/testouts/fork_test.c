#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int main() { 
    int fd = fork();

    if(fd) { 
        //parent part
        int wstatus;
        int chpid = wait(&wstatus);
        printf("child pid: %d\n", chpid);
        printf("child exited with %d\n", WEXITSTATUS(wstatus));
    } else { 
        int f = execlp("lsp", "lsp", NULL); 
        printf("Child failed with %d\n", f);
        printf("Errno is: %d\n", errno);

        return 42; 
    }





    return 0;
}