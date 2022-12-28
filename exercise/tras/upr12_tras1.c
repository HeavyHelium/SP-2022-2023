#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int args, char *argv[]) {
  int fdr, fdw, n_byt, i = 0, status;
  char symbols[40], c;
  if(fork()) {

    wait(&status);
    if (open("file_second", O_RDONLY) != -1)
		write(1, "\n", 1);
  
    execlp("grep", "grep", "234", "file_second", 0); // execute grep 234 on file_second
	// result will be:
	// 12345 
	// eight times 12345
    execlp("wc", "wc", "-l", "file_second", 0); // will not reach this part
  
  } else { // Child will be executed first, parent waits for it
    
	if ((fdr = open("file_first.txt", O_RDONLY)) == -1) { // open file for reading
      printf("\n Cannot open \n");
      exit(1);
    }
    
	if ((fdw = open("file_second", O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1) // open second file for reading and writing
    {
      printf("\n Cannot open \n");
      exit(1);
    }

    n_byt = read(fdr, symbols, 22);// read the whole first file
    write(fdw, "12345\n", 6); // write "12345\n" in the second file
    c = symbols[i++]; // c is '2'
    if (c >= '0' && c <= '9')
    {
      while (symbols[i++] != '\n' && i < n_byt) 
        write(fdw, "12345", 5); // write "12345" in the second file for a total of 8 times
      write(fdw, "\n", 1); // write a new line to the second file
      write(1, "AAA\n", 4); // write "AAA" to the standard output
    } else {// will not reach this part 
      write(1, symbols, n_byt);
      write(fdw, symbols, 8);
      write(1, "\n", 1);
    }
    write(fdw, "AAA\n", 4); // write "AAA" to the second file
    write(1, symbols, 12); // write "123456789\nAA" to the standard output
    close(fdr);
    close(fdw);
  }

}

/**
 file_second
 12345
 1234512345123451234512345123451234512345
 //new line
  AAA
*/

/**
STDOUT

AAA
123456789
AA
// grep result will be:
12345 
eight times 12345
*/

/*
file_first.txt

123456789 
AABBCCDDE
*/