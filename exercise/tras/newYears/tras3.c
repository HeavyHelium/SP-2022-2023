#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char** argv) {
	int fd, fd1, i = 0 ;
	char c;
	
    // open the fileA.txt for reading

    if((fd = open(argv[1], O_RDONLY)) == -1) {  
        printf("\n Cannot open %s", argv[1]);	
        exit(1);  	
    }

    // open the file1 for reading & writing
    // clean its content, if any  
    if((fd1 = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, 0644)) == -1) {  
        printf ("\n Cannot open %s ", argv[2]);
        exit(1);  	
    }

    // read from fileA.txt and write to file1
    // do so byte by byte
	while(read(fd, &c, 1)) {	
        ++i;
		if(c == '\n') {    
            if(i < 10)  
                for(i; i < 15; i++) { 
                    write(1, "$", 1); 
                    write(fd1, "#", 1);
                }
                i = 0;
        }
        write(1,&c,1);     			
	}
    // write abc123-x to stdout// i is 9, after reading '\n'
    // write "$$$$$$" to stdout// i is 15
    // and new line
    // write "######" to file1
    // i is reset to 0
    // write 999aaa to stdout//i is 7, after reading '\n'    
    // write "$$$$$$$$" to stdout// i is 15
    // and new line
    // write "########" to file1
    // i is reset to 0
    // write yyyyyy6xxxxx// i is 13 >= 10, after reading '\n'
	
    close(fd); 
    close(fd1);

    return 0;
}

/*
STDOUT:
abc123-x$$$$$$
999aaa$$$$$$$$
yyyyyy6xxxxx



==============
file1:
######
########
##
*/