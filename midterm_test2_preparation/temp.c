#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


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

