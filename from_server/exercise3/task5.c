#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int is_digit(char ch) { 
	return ch >= '0' && ch <= '9'; 
}


int main(int argc, char** argv) { 
	char buffer[1];

	if(argc != 3) { 
		return -1;
	}

	int fd = open(argv[1], O_RDONLY);

	int prev_dollar = 0; // to be interpreted as a boolean
	char line[62];
	int cnt = 1;
	int i = 0;	
	int fd2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	char temp[1];
	while(read(fd, buffer, 1)) {
		if(prev_dollar && buffer[0] == '\n') { 
			//printf("%d", 42);
			line[i++] = '\n';
			write(1, line, i);		
		} 
		if(buffer[0] == '\n') {
			for(int j = 0; j < i; ++j) { 
				if(is_digit(line[j])) {
					temp[0] = line[j]; 
					write(fd2, temp, 1);
				}
			}
			write(fd2, "\n", 1); 
			i = 0;
			prev_dollar = 0;
			
		} else {
			if(buffer[0] == '$') { 
				prev_dollar = 1;
			} else { 
				prev_dollar = 0;
			}
			line[i++] = buffer[0];
		} 
	}
	
	if(prev_dollar) { 
		write(1, buffer, i);
	}	
	

	return 0;
}
