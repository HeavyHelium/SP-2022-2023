#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main() { 

	int  a = 2000;
	if ( fork()  )  { // parent  
		a /= 2;  // a is 1000
              printf ("\nStoinostta na a = %d ", a ) ; 
        } else  {  
	   if ( fork() ) { // child
		a *= 2; // 4000 
                printf ("\nStoinostta na a = %d ", a) ; 
                if (execlp("ps", "ps", "-u", "student", 0 ) == -1 ) {  
                	a = a + 2; 
                	printf ("\nStoinostta na a = %d", a);   
		}
           } else { // grandchild   
		a += 2;
                printf ("\nStoinostta na a = %d ", a ) ; 
	   }
        }
	
	a++;
	printf ("\nStoinostta na a = %d ", a);  

	return 0;
}


/*
 
STDOUT:
Stoinostta na a = 1000
Stoinostta na a = 1001
Stoinostta na a = 2002
Stoinostta na a = 2003
Stoinostta na a = 4000
Output of ps, which is the active of processes of the user student 
 
 
 
 */
