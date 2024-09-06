/*
============================================================================
Name : 7.c
Author : Vaibhav Dewangan
Description : Write a program to copy file1 into file2 ($cp file1 file2)
Date: 26th Aug, 2024.
============================================================================
*/



#include <fcntl.h>   
#include <unistd.h>  
#include <stdio.h>   
#include <stdlib.h>  

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int source_fd, dest_fd;   
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        write(2, "Usage: ./cp file1 file2\n", 24);
        exit(EXIT_FAILURE);
    }

    source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }


    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening/creating destination file");
        close(source_fd);  
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading source file");
    }

    close(source_fd);
    close(dest_fd);

    return 0;
}


/* output
=============================================================
Usage: ./cp file1 file2
=============================================================
*/
