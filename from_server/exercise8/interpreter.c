#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>


const char* EXIT = "exit";
const char* ERROR_MESSAGE = "Execution failed!\n";

#define TRUE 1
#define FALSE 0


int is_whitespace(char ch) { 
	return ch == ' ' || ch == '\t';
} 


int main() { 
	
	char buffer[300];	
	char ch;	
	int cid = 0;
		
	int prev_lf = TRUE;
	char num_buffer[30];
	
	while(TRUE) {
		if(prev_lf) { 
			write(1, "> ", 2);
		}

		read(0, &ch, 1);
		if(is_whitespace(ch)) { { 
			prev_lf = FALSE;
 			continue;
		}
		if(ch != '\n') { 
			buffer[cid++] = ch;
			prev_lf = FALSE;

		} else {
			if(cid <= 1) { 
				cid = 0;
				continue;
			}
			prev_lf = TRUE;
			buffer[cid] = '\0';	
			int prev_amp = buffer[cid - 1] == '&';
			if(prev_amp) {
				printf("here\n"); 
				buffer[cid - 1] = '\0';
			}
			cid = 0;
			if(strcmp(buffer, EXIT) == 0) {
				break; 
			} 
			int chpid;
			
			if((chpid = fork()) == 0) { 
				if(execlp(buffer, buffer, NULL) == -1) { 
					return -1;
				}
			} else { 
				int wstatus;
				if(!prev_amp) {
					wait(&wstatus);
					if(wstatus) { 
						write(1, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
					}
				} else {
					// write(1, "42\n", 3);
					sprintf(buffer, "Executing child with pid: %d\n", chpid);
					write(1, buffer, strlen(buffer));
				}
				
			} 
		}	
	}
	
	return 0;
}
