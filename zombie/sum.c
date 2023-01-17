#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>


int main() { 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(*arr);
    int fd[2];
    int begin, end;
    if(pipe(fd) == -1) { 
        return 1;
    }
    int child_id = fork(); 
    if(!child_id) { 
        begin = size / 2;
        end = size;
        close(fd[0]);
    } else { 
        begin = 0;
        end = size / 2;
        close(fd[1]);
    }
    int sum = 0;
    for(int i = begin; i < end; ++i) { 
        sum += arr[i];
    }
    if(!child_id) { 
        write(fd[1], &sum, sizeof(sum));
    } else { 
        int other_sum;
        wait(NULL);
        read(fd[0], &other_sum, sizeof(other_sum));
        printf("Total sum is: %d\n", other_sum + sum);
    }
}