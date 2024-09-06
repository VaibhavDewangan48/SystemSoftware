/*
============================================================================
Name : 25.c
Author : Vaibhav Dewangan
Description : Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call)
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(){
    int status;
    pid_t pid,child_pid[3];
    pid_t pid1,pid2,pid3;
    pid1=fork();
    if(pid1==-1){
        printf("fork failed for pid1");
    }else{
        printf("child process 1\n");
    }
    pid2=fork();
    if(pid2==-1){
        printf("fork failed for pid1");
    }else{
        sleep(10);
        printf("child process 2\n");
    }
    pid3=fork();
    if(pid3==-1){
        printf("fork failed for pid1");
    }else{
        printf("child process 3\n");
    }
    pid_t pickpid=pid2;
    printf("parent waiting for pid%d\n",pickpid);
    pid=waitpid(pickpid, &status, 0);
    if(pid==-1){
        printf("waitpid error\n");
    }
    if(WIFEXITED(status)){
        printf("Parent: Child with PID %d exited with status %d\n",pid,WIFEXITED(status));
    }
}
/*
output
=============================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/handson/problem25$ ./25 
child process 1
child process 1
child process 2
child process 3
child process 2
child process 3
parent waiting for pid53333
parent waiting for pid53332
child process 2
child process 2
child process 3
child process 3
parent waiting for pid0
child process 3
parent waiting for pid53332
waitpid error
Parent: Child with PID -1 exited with status 1
child process 3
parent waiting for pid53333
waitpid error
Parent: Child with PID -1 exited with status 1
child process 3
parent waiting for pid0
waitpid error
Parent: Child with PID -1 exited with status 1
child process 3
parent waiting for pid0
waitpid error
Parent: Child with PID -1 exited with status 1
parent waiting for pid0
Parent: Child with PID 53341 exited with status 1
Parent: Child with PID 53340 exited with status 1
Parent: Child with PID 53333 exited with status 1
Parent: Child with PID 53332 exited with status 1
===========================================================================
*/
