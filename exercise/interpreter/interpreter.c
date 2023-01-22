#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


const char* EXIT = "exit";
const char* ERROR_MESSAGE = "Execution failed!\n";
const char* FILE_FAILURE = "File operation failure!\n";
const char* BYE_MSG = "See you next time!\n";


#define TRUE 1
#define FALSE 0

enum { BACKGROUND, NORMAL };

int ends_with_ampersand(char* str) { 
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
        return ch == ' ' || 
               ch == '\t' || 
               ch == '\n';
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
        if(!empty && ends_with_ampersand(*(r - 1))) {
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

void split(char delimiter, 
           char* line, 
           char* str1, 
           char* str2) { 
    while(*line && *line != delimiter) {
        *str1++ = *line++;
    }
    *str1 = '\0';
    if(*line == delimiter) {
        ++line;
    }
    while(*line) {
        *str2++ = *line++;
    }
    *str2 = '\0';
}

int in(char ch, const char* str) { 
    while(*str) {
        if(*str == ch) {
            return TRUE;
        }
        ++str;
    }
    return FALSE;
}

int split_multi(const char* delimiters, 
                char* line, 
                char* str1, 
                char* str2) { 
    int del = -1;
    while(*line && !in(*line, delimiters)) {
        *str1++ = *line++;
    }
    *str1 = '\0';
    if(*line && in(*line, delimiters)) {
        del = *line;
        ++line;
    }
    while(*line) {
        *str2++ = *line++;
    }
    *str2 = '\0';
    return del;
}

void interpret_cmd(char* line) { 
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

void interpret_pipe(char** cmd1, char** cmd2) { 
    if(fork()) { 
        int wstatus;
        waitpid(-1, &wstatus, 0);
        if(wstatus) {
            write(2, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
        }
    } else { // child handles commands
        int fd[2];
        pipe(fd);
        int pid = fork();
        if(pid) { 
            close(fd[1]);
            dup2(fd[0], 0);
            close(fd[0]);
            execvp(cmd2[0], cmd2);
            exit(1);
        } else { 
            close(fd[0]);
            dup2(fd[1], 1);
            close(fd[1]);
            execvp(cmd1[0], cmd1);
            exit(1);
        }
    }
}

void interpret_redirect_right(char** cmd1, const char* filename) { 
    if(fork()) { 
        int wstatus;
        waitpid(-1, &wstatus, 0);
        if(wstatus) {
            write(2, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
        }
    } else { // child handles commands
        int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(fd == -1) {
            write(2, FILE_FAILURE, strlen(FILE_FAILURE));
            exit(1);
        }
        dup2(fd, 1);
        close(fd);
        execvp(cmd1[0], cmd1);
        exit(1);
    }
}

void interpret_redirect_left(char** cmd1, const char* filename) { 
    if(fork()) { 
        int wstatus;
        waitpid(-1, &wstatus, 0);
        if(wstatus) {
            write(2, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
        }
    } else { // child handles commands
        int fd = open(filename, O_RDONLY);
        if(fd == -1) {
            write(2, FILE_FAILURE, strlen(FILE_FAILURE));
            exit(1);
        }
        dup2(fd, 0);
        close(fd);
        execvp(cmd1[0], cmd1);
        exit(1);
    }
}

void interpret_line(char* line) { 
    char part1[80], part2[80];
    char delimiters[] = "|><";
    int del = split_multi(delimiters, line, part1, part2);
    char* t1[80];
    char* t2[80];
    tokenize(part1, t1);
    tokenize(part2, t2);

    if(del == -1) {
        interpret_cmd(line);
    } else if(del == '|') {
        interpret_pipe(t1, t2);
    } else if(del == '<') {
        if(!*t2) {
            write(2, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
            return;
        }
        interpret_redirect_left(t1, t2[0]);
    } else if(del == '>') {
        if(!*t2) {
            write(2, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
            return;
        }
        interpret_redirect_right(t1, t2[0]);
    } else {
        write(2, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
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

