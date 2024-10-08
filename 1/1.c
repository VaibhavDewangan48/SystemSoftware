/*
============================================================================
Name : 1.c
Author : Vaibhav Dewangan
Description : Create the following types of a files using 
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 23th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
    int v=symlink("demo.txt", "destSL");
    if(v<0){
        perror("Failed");
        return 1;
    }
    int f=link("demo.txt", "destHL");
    if(f<0){
        perror("failed");
        return 1;
    }
    int e=mknod("destFIFO", S_IFIFO, 0);
    if(e<0) perror("Failed");
    return 0;
}
