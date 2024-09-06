/*
============================================================================
Name : 3.c
Author : Vaibhav Dewangan
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 24th Aug, 2024.
============================================================================
*/

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
const char *demo = "demo.txt";
mode_t mode = 0644;
int fd = creat(demo,mode);
if(fd == -1){
perror("creat failed");
return 1;
}

printf("File : '%s' file descriptor : %dn",demo,fd);
close(fd);

return 0;
}



/* output = File : 'demo.txt' file descriptor : 3n*/

