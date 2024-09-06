/*
============================================================================
Name : 27b.c
Author : Vaibhav Dewangan
Description : Write a program to execute ls -Rl by the following system call
b. execlp
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
int main()
{
    // it will use environment variable PATH to run executable PATH .
    // it does not required entire file path as we did in execl().
    char *path = "ls";
    execlp(path, path, "-Rl", NULL);
    return 0;
}
/*
output
=========================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/handson/problem27$ ./27b
.:
total 40
-rwxrwxr-x 1 vaibhavd vaibhavd 15952 Aug 30 20:23 27a
-rw-rw-r-- 1 vaibhavd vaibhavd   789 Aug 30 20:24 27a.c
-rwxrwxr-x 1 vaibhavd vaibhavd 15952 Aug 30 20:29 27b
-rw-rw-r-- 1 vaibhavd vaibhavd   574 Aug 30 20:29 27b.c
=========================================================================
*/
