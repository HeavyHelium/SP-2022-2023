#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


const char* EXIT = "exit";
const char* ERROR_MESSAGE = "Execution failed!\n";
const char* BYE_MSG = "See you next time!\n";


#define TRUE 1
#define FALSE 0

enum { BACKGROUND, NORMAL };

int ends_with_ampesand(char* str) { 
    if(str) { 
        while(*str) {
            if(*str == '&' && *(str + 1) == '\0') {
                *str = '\0';  
                
                return TRUE;
            }
            ++str;
        }
    }
    
    return FALSE;
}

int is_whitespace(char ch) {
        return ch == ' ' || ch == '\t' || ch == '\n';
}

int tokenize(char* cmd, char** r) {
        int empty = TRUE;
        while(*cmd) {
                while(is_whitespace(*cmd)) {
                    ++cmd;
                }
                if(*cmd) { 
                        *r++ = cmd; // new beginning
                        empty = FALSE;
                        while(!is_whitespace(*cmd) && *cmd) {
                                ++cmd;
                        }
                        if(!*cmd) { 
                                break;
                        }
                        *cmd = '\0';
                        ++cmd;
                }
        }
        if(!empty && ends_with_ampesand(*(r - 1))) {
            if(strlen(*(r - 1)) == 0) { 
                 *(r - 1) = NULL;
            } else { 
                *r = NULL; 
            }
            return BACKGROUND;
        }
        
        *r = NULL;
        return NORMAL;
        
}

void read_line(char* buffer) { 
        char ch;
        while(read(0, &ch, 1)) { 
                if(ch == '\n') {
                        *buffer = '\0';
                        return;
                }
                *buffer++ = ch;
        }
}


void interpret_line(char* line) { 
    char* res[80];
    int mode = tokenize(line, res);
    if(!*res) { // empty line
        return;
    }

    if(strcmp(res[0], EXIT) == 0) {
        write(1, BYE_MSG, strlen(BYE_MSG));
        exit(0);
    }
    
    int pid = fork();
    
    if(pid) { 
        if(mode == NORMAL) {
            int wstatus;
            waitpid(pid, &wstatus, 0);
            
            if(wstatus) {
                write(2, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
            }
        }

    } else { 
        if(mode == BACKGROUND) {
            char buff[30];
            sprintf(buff, "PID: %d\n", getpid());
            write(1, buff, strlen(buff));
        }
        execvp(res[0], res);
        exit(1);
    }
}



void interpreter() { 
    char line[80];

    while(TRUE) {
        write(1, "$ ", 2);
        read_line(line);
        interpret_line(line);
    }
}

int main() { 
    interpreter();

    return 0;    
}


