/*
============================================================================
Name : 27a.c
Author : Vaibhav Dewangan
Description : Write a program to execute ls -Rl by the following system calls
a. execl
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
int main()
{
    char *path = "/bin/ls";
    execl(path, path, "-Rl", NULL);
    return 0;
}
/*
output
===========================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/handson/problem27$ ./27a 
.:
total 20
-rwxrwxr-x 1 vaibhavd vaibhavd 15952 Aug 30 20:23 27a
-rw-rw-r-- 1 vaibhavd vaibhavd   441 Aug 30 20:23 27a.c
===========================================================================
*/

