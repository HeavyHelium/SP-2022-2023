#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int is_whitespace(char ch) {
    return ch == ' ' ||
           ch == '\n' ||
           ch == '\t';
}

int main(int argc, char** argv) {
    if(argc != 2) {
        return -1;
    }
    int fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        return fd;
    }
    int char_cnt, word_cnt, line_cnt;
    char_cnt = word_cnt = line_cnt = 0;
    char buff[1];
    int started_word = 0;
    int whitespace;
    while(read(fd, buff, 1)) {
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

    printf(" %d  %d %d %s\n", line_cnt, word_cnt, char_cnt, argv[1]);
    return 0;
}