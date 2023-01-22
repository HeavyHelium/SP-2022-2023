#include <stdio.h>
#include <fcntl.h>


int main(int args, char *argv[]) { 
	int fdr, fdw, n_byt, i = 0, status;
 	
	char symbols[40], c;
 	
	if(fork()) { // parent 
		wait(&status); // wait for child
     		if(open("file_second", O_RDONLY) != -1)
       			write(1,"\n",1); // write a new line to STDOUT
        	execlp("grep", "grep", "234", "file_second", 0); // look for "234" will print out 
        	execlp("wc", "wc","-l","file_second",0);
    	} else { // child executes first
		if ((fdr = open("file_first.txt", O_RDONLY)) == -1) { // open file
			printf("\n Cannot open \n"); 
			exit(1); 
		}
       		if((fdw = open("file_second", O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1) { // open second file  
			printf("\n Cannot open \n"); 
			exit(1);
		}
     		n_byt = read(fdr, symbols, 22); // read whole "123456789"
     		write(fdw, "12345\n", 6); // write 12345CDDE to new file
    		c = symbols[i++]; // c is 1
    		if(c>='0' && c <='9') { // fwd is: 12345\n12345\n12345 all nine times 
			while (symbols[i++] != '\n' && i<n_byt) 
                	write(fdw, "12345",5);
       			write(fdw,"\n",1);
       			write(1,"AAA\n",4); // 8 times this to stdout
      		} else {
			write(1, symbols,n_byt); 
          		write(fdw, symbols,8);
           		write(1,"\n",1);
         	}
       		write(fdw,"AAA\n",4);
       		write(1,symbols,12);
       		close(fdr); 
		close(fdw);
       }
}
file_first.txt

123456789
AABBCCDDE
