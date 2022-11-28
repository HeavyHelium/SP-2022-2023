#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int fd ;
	// save where true standard output is
	fd = dup(1);
	// print new fd, which points to true standard output
	printf("fd = %d\n", fd );

	// write "Hello" to standard output
	write(1, "Hello", sizeof ("Hello" ));
	// write "-guys" to standard output
	write ( fd, "-guys" , sizeof ( "-guys" ) );
	// write "-and Goodbye" to standard output
	write ( 1, "-and Goodbye!\n", 14 );

	// close the 1 fid
	close ( 1 );
	// this one is closed, it will not be printed
	write ( 1, "No\n", sizeof ( "No\n" ) ) ;
	// this one is still active and "Yes" will be printed to standard output
	write ( fd, "Yes\n", sizeof ( "Yes\n" ) ) ;
} 
