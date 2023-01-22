#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int is_whitespace(char ch) {
    return ch == ' ' ||
           ch == '\n' ||
           ch == '\t';
}

int main(int argc, char** argv) { 
	int fd[100];
	int chars = 0;
	int words = 0;
	int lines = 0;
	
	for(int i = 1; i < argc; ++i) { 
		if((fd[i] = open(argv[i], O_RDONLY)) == -1) { 
			return -1;
		}
	}	
	int char_cnt, word_cnt, line_cnt;
	for(int i = 1; i < argc; ++i) { 
        	char_cnt = word_cnt = line_cnt = 0;
        	char buff[1];
        	int started_word = 0;
       		int whitespace;
       		while(read(fd[i], buff, 1)) {
                	++char_cnt;
                	whitespace = is_whitespace(buff[0]);
                	if(!started_word && !whitespace) {
                       		started_word = 1;
                        	++word_cnt;
                	}
                	if(whitespace && started_word) {
                       		started_word = 0;
               		}
                	if(buff[0] == '\n') {
                	        ++line_cnt;
                	}
        	}
        	if(started_word) {
                	++word_cnt;
        	}

        	printf(" %d  %d %d %s\n", line_cnt, word_cnt, char_cnt, argv[i]);
		
		chars += char_cnt;
		lines += line_cnt;	
		words += word_cnt;
	}
	printf(" %d  %d %d %s\n", lines, words, chars, "total");
		
	return 0;
}

