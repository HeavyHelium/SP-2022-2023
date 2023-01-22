#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>



int main() {
	int fdi, fdio, nb1, nb2;

	char buff[15] ;
		
	fdi = open("ABC", O_RDONLY); // open file for reading
        fdio = open("ABC", O_RDWR); // open file for writing
 
        nb1 = read(fdi, buff, 6); // read "Let's "
        write(1, buff, nb1); // write "Let's " to stdout

	// Let's go |
        lseek(fdi, 3, SEEK_CUR); // lseek 3 bytes forward 
        nb1 = read(fdi, buff, 6); // "light " 
        write(1, buff, nb1); // write "light " to stdout

        lseek( fdio,-20,SEEK_END); //| light up the world!
	write( fdio, "disc", 4); //Let's go disc|ht up the world!

       	write(fdio, "over", 4); // Let's go discover| the world!
       	nb2 = read(fdio, buff, 5);// " the "
        write(1, buff, nb2);  // print  " the "  to stdout
        write(1, "sky", 3); // print "sky" to stdout

        lseek(fdi, -2, SEEK_END); // go to the "!" byte
        nb2 = read(fdi, buff, 2); // read it
        write(1, buff, nb2); // print it
}

// stdout: 
// "Let's light  the sky!"
//
// file: 
// Let's go discover the world!
