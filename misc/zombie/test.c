#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


int main(int argc, char** argv) { 
    for (size_t i = 1; i < argc; ++i) {
        if(fork()) { 
            int wstatus;
            int child_id = wait(&wstatus);
            if(wstatus)
                printf("child process with id %d failed", child_id);
        } else { 
            return execlp(argv[i], argv[i], NULL);
        }
    }
    return 0;
}