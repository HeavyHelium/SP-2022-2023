#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

// Let's go change the world!
int main() { 

    int fdi, fdio, nb1, nb2;
    char buff[15];	
	fdi = open("abc", O_RDONLY); // one file descriptor for reading only
    fdio = open("abc", O_RDWR); // one file descriptor for reading and writing

    nb1 = read(fdi, buff, 6); // read "Let's "
    write(1, buff, nb1); // write "Let's " to STDOUT

    lseek(fdi, 3, SEEK_CUR); // |change the world
    nb1 = read(fdi, buff, 6); // read "change"
    write(1, buff, nb1); // write it to STDOUT

    lseek(fdio, -18, SEEK_END);// |change the world!
    write(fdio, "tra", 3);// tra|nge the world!

    write(fdio, "vel", 3); // travel| the world! 
    nb2 = read(fdio, buff, 5); // travel the |world!
    write(1, buff, nb2);// write " the " to STDOUT
    write(1, "time", 4); // write "time" to STDOUT

    lseek(fdi, -2, SEEK_END); // |!
    nb2 = read(fdi, buff, 2); 
    write ( 1, buff, nb2); // write "!\n" to STDOUT


    return 0;
}

/*
STDOUT: 
Let's change the time!

In file abc: 
Let's go travel the world!

*/