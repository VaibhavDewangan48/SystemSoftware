/*
============================================================================
Name : 11b.c
Author : Vaibhav Dewangan
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
b. use dup2
Date: 26th Aug, 2024.
============================================================================
*/
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
  
int main()
{
    int file_desc = open("test.txt",O_WRONLY | O_APPEND);
    dup2(file_desc, 1) ; 
    printf("I will be printed in the file test.txt\n");
    return 0;
}
/*
output
===========================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/handson/problem11$ gcc -o 11b 11b.c
vaibhavd@vaibhav-X509UA:~/Desktop/handson/problem11$ ./11b
vaibhavd@vaibhav-X509UA:~/Desktop/handson/problem11$ cat test.txt
Jai Hind !!!!
I will be printed in the file test.txt
===========================================================================
*/
