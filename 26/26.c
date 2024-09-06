/*
============================================================================
Name : 26.c
Author : Vaibhav Dewangan
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name
Date: 28th Aug, 2024.
============================================================================
*/


#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }
    printf("Hello, %s!\n", argv[1]);
    return 0;
}
/*
============================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/handson/problem26$ ./26 file26.txt 
Hello, file26.txt!
============================================================================
*/
