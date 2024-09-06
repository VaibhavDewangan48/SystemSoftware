/*
============================================================================
Name : 27d.c
Author : Vaibhav Dewangan
Description : Write a program to execute ls -Rl by the following system call
                    d. execv
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    // Path to the executable
    char *path = "/bin/ls";
    
    // Arguments for the command
    char *args[] = {"ls", "-Rl", NULL};
    
    // Executing the ls command with -Rl options
    if (execv(path, args) == -1) {
        perror("execv failed");
    }

    // This line will only be reached if execv fails
    return 1;
}

/*
output
========================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/handson/problem27$ ./27d
.:
total 80
-rwxrwxr-x 1 vaibhavd vaibhavd 15952 Aug 30 20:23 27a
-rw-rw-r-- 1 vaibhavd vaibhavd   789 Aug 30 20:24 27a.c
-rwxrwxr-x 1 vaibhavd vaibhavd 15952 Aug 30 20:29 27b
-rw-rw-r-- 1 vaibhavd vaibhavd  1026 Aug 30 20:30 27b.c
-rwxrwxr-x 1 vaibhavd vaibhavd 16048 Aug 30 20:40 27c
-rw-rw-r-- 1 vaibhavd vaibhavd  1441 Aug 30 20:42 27c.c
-rwxrwxr-x 1 vaibhavd vaibhavd 16048 Aug 30 20:50 27d
-rw-rw-r-- 1 vaibhavd vaibhavd   715 Aug 30 20:50 27d.c
========================================================================
*/
