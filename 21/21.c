/*
============================================================================
Name : 21.c
Author : Vaibhav Dewangan
Description : Write a program, call fork and print the parent and child process id.
Date: 27th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>
int main(){
    pid_t parent= getppid();
    pid_t process= getpid();
    pid_t pid=fork();
    printf("child process: %d\n",process);
    printf("parent process: %d\n",parent);
return 0;
}
/*
output
===========================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/handson/problem21$ ./21 
child process: 51855
parent process: 51796
===========================================================================
*/

