# A Few Details About The Main Function in C

## How to properly define the main function

### The name is ```main``` and that is absolutely clear.

### The *return type* is more interesting

* it is ***exclusively*** ```int```

    * Cannot be ```void``` or ```float``` or anything else. 

* **the return type can be omitted** **but** that is considered obsolete

    * the reason why is due to the language's backwards compatibility

* Also, the language specification makes it clear that **if no return statement is explicitly provided**, ***then an empty return statement is automatically added by the compiler***

```Note: ``` ```return;``` is the same as ```return 0;``` in the main fuction.  

``` Note: ``` The return code is an exit code. If the process exited with code 0, then it is considered to have ended successfully. Any exit value other than 0, means unsuccessful exit.

### **The parameter list**
* **can be empty**

* can have at the very least 2 parameters

    * namely, often called **argc** and **argv**, which we know all about

    * thus defined it would work on any OS and C compiler

```c
int main(int argc, char** argv) { // of course, instead of char**, 
                                  // you could type char* argv[]
}
```  

* apart from those 2, **it can have a third parameter**, which is supported by most compilers

    * often named ```envp```

    * what it stores is the environment variables, which you usually set in the environment varible system settings

        * every single program runs inside an evironment with some variables set



#### **On the third parameter...**

* whereas both ```argv``` and ```envp``` are null-terminated, that is, they end with NULL, **for envp the number of elements is not directly provided**

```c
int main(int argc, char** argv, char** envp) { 
}

```

* the third parameter offers a way to get the environment variables in your program 