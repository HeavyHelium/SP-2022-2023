#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

// 123456789
// $$abcdefg


int main( ) {       
	int fdr, fdw, n_byt, i = 0 , status;
	char symbols[40], c;	
	
	if (fork( )) {  
		wait ( &status);
	        if ( open ("file_new", O_RDONLY ) != -1 ) { 
			write ( 1, "\n", 1 ); // write line feed
		        execlp ("wc", "wc", "-c", "file_new",0 );
				// size of filenew is 11`
                        execlp ("head", "head", "-5c", "file_new",0 );
                }
	} else { // child executes first
		// open file
		if  (  ( fdr = open ("fileD.txt",O_RDONLY ) ) == -1 ) { 
			printf ("\n Cannot open  \n" );  
			exit (1);  
		}
		/// new file
		if (( fdw=open ("file_new", O_CREAT|O_TRUNC|O_RDWR,0666 )) == -1 ) { 
			printf ("\n Cannot creat  \n" );  
			exit (1);  
		}
		// read the whole file
		n_byt = read(fdr , symbols, 40);
		
		c = symbols[i++]; // c is 1
		if  ( c >= '0' && c <= '9' ) { // condition is true	
			while  ( symbols [ i ++] != '\n' && i < n_byt )
                       	 write ( fdw, "$", 1 ); // write 9 dollars to new file
                        write ( fdw, "\n", 1 ); // write linefeed to file
                        write ( 1, "\n", 1 ); // write linefeed to stdout
		} else { // will not be reached
			write( 1,  symbols, n_byt );  write ( 1, "\n", 1 ); 
                }
			// write $ linefeed to newfile
                write ( fdw, "$\n", 2 );
                write ( 1, symbols, 12); // write "123456789\n$$" to stdout
                close ( fdr); close (fdw);
	 }
}
