/*
============================================================================
Name : 12.c
Author : Vaibhav Dewangan
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 26th Aug, 2024.
============================================================================
*/
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
    FILE *file = fopen("file12.txt", "r");
    int fd = fileno(file);
    int mode = fcntl(fd, F_GETFL);
    printf("mode of file descriptor is: %d\n",mode);
    return 0;
    
}
/*
output 
==========================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/handson/problem12$ ./12
mode of file descriptor is: 32768
===========================================================================
*/
