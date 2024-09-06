/*
============================================================================
Name : 4.c
Author : Vaibhav Dewangan
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 24th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    const char *file1 = "problem4.txt";
    int fd = open(file1, O_RDWR);
    if (fd == -1) {
        perror("Error opening file in RW mode");
        return 1;
    }

    printf("File opened successfully in read-write mode (fd: %d)\n", fd);

   
    fd = open(file1, O_RDWR | O_CREAT | O_EXCL, 0666);
    if (fd == -1) {
        if (errno == EEXIST) {
            printf("File already exists, and O_EXCL was specified. Open failed.\n");
        } else {
            perror("Error");
        }
        return 1;
    }

    printf("File is open with O_EXCL (fd: %d)\n", fd);

    
    close(fd);

    return 0;
}

/*output*/
/*File opened successfully in read-write mode (fd: 3)
File already exists, and O_EXCL was specified. Open failed.*/
