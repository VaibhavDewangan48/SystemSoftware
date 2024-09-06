/*
============================================================================
Name : 27e.c
Author : Vaibhav Dewangan
Description : Write a program to execute ls -Rl by the following system calls
                  e. execvp
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
    char *argv[] = {path, "-Rl", NULL};
    execvp(path, argv);
    return 0;
}
/*
output
=========================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/handson/problem27$ ./27e
.:
total 100
-rwxrwxr-x 1 vaibhavd vaibhavd 15952 Aug 30 20:23 27a
-rw-rw-r-- 1 vaibhavd vaibhavd   789 Aug 30 20:24 27a.c
-rwxrwxr-x 1 vaibhavd vaibhavd 15952 Aug 30 20:29 27b
-rw-rw-r-- 1 vaibhavd vaibhavd  1026 Aug 30 20:30 27b.c
-rwxrwxr-x 1 vaibhavd vaibhavd 16048 Aug 30 20:40 27c
-rw-rw-r-- 1 vaibhavd vaibhavd  1441 Aug 30 20:42 27c.c
-rwxrwxr-x 1 vaibhavd vaibhavd 16048 Aug 30 20:50 27d
-rw-rw-r-- 1 vaibhavd vaibhavd  1385 Aug 30 20:51 27d.c
-rwxrwxr-x 1 vaibhavd vaibhavd 16000 Aug 30 20:52 27e
-rw-rw-r-- 1 vaibhavd vaibhavd   292 Aug 30 20:52 27e.c
==========================================================================
*/

