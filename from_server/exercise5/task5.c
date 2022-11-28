#include <fcntl.h>
#include <stdio.h>

// ABC: 
// Let's go change the world!


int main() {
	int fdi, fdio, nb1, nb2;
	
	char buf[15];	
	fdi = open("abc", O_RDONLY);
        fdio = open("abc", O_RDWR);
 
	/// Let's |
	
        nb1 = read(fdi, buf, 6);
        write(1, buf, nb1); // write "Let's " to stdout

        lseek(fdi, 3, SEEK_CUR); // Let's go | 
        nb1 = read(fdi, buf, 6);// Let's go |change| 
        write(1, buf, nb1); // write "change" to stdout

        lseek(fdio, -18, SEEK_END); // Let's go| tra|nge the world!
	write(fdio, "tra", 3);

        write(fdio, "vel", 3); // Let's go travel| the world!
        nb2 = read(fdio, buf, 5);// " the "
        write(1, buf, nb2); // write " the " to stdout
        write(1, "time", 4); // write "time" to stdout

        lseek(fdi, -2, SEEK_END); // go to the "!"
        nb2 = read(fdi, buf, 2);
        write(1, buf, nb2); // write "!" to stdout


	return 0;
}

// stdout:
// Let's change the time!
//
//
// abc: 
// Let's go travel the world! 
