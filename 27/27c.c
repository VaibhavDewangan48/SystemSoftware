/*
============================================================================
Name : 27c.c
Author : Vaibhav Dewangan
Description : Write a program to execute ls -Rl by the following system calls
                      c. execle
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
    
    // Environment variables (can be NULL if you don't want to modify the environment)
    char *envp[] = {NULL};
    
    // Executing the ls command with -Rl options
    if (execle(path, args[0], args[1], (char *)NULL, envp) == -1) {
        perror("execle failed");
    }

    // This line will only be reached if execle fails
    return 1;
}


/*
output
===========================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/handson/problem27$ ./27c 
.:
total 60
-rwxrwxr-x 1 vaibhavd vaibhavd 15952 Aug 30 20:23 27a
-rw-rw-r-- 1 vaibhavd vaibhavd   789 Aug 30 20:24 27a.c
-rwxrwxr-x 1 vaibhavd vaibhavd 15952 Aug 30 20:29 27b
-rw-rw-r-- 1 vaibhavd vaibhavd  1026 Aug 30 20:30 27b.c
-rwxrwxr-x 1 vaibhavd vaibhavd 16048 Aug 30 20:40 27c
-rw-rw-r-- 1 vaibhavd vaibhavd   540 Aug 30 20:39 27c.c
===========================================================================
*/
