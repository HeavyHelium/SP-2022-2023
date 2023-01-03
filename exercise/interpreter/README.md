# Dish shell interpreter
Dish is a limited bash interpreter, which supports\:   
* piping, but only two commands for a line
* output redirection to file, but only for 1 command at a time
* input redirection from file, but only for 1 command at a time

## How to run Dish
```sh
$ gcc -stc=c99 interpreter.c -o dish && ./dish
```
