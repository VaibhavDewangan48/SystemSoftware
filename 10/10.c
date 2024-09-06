/*
============================================================================
Name : 10.c
Author : Vaibhav Dewangan
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data
Date: 26th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    ssize_t bytes_written;
    off_t offset;

    
    fd = open("testfile.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    
    bytes_written = write(fd, "1234567890", 10);
    if (bytes_written != 10) {
        perror("Error writing the first 10 bytes");
        close(fd);
        return 1;
    }

    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == -1) {
        perror("Error with lseek");
        close(fd);
        return 1;
    } else {
        printf("lseek returned: %ld\n", offset);
    }

    bytes_written = write(fd, "ABCDEFGHIJ", 10);
    if (bytes_written != 10) {
        perror("Error writing the second 10 bytes");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}

/* output
============================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/handson/program10$ ./10 
lseek returned: 20
vaibhavd@vaibhav-X509UA:~/Desktop/handson/program10$ od -c testfile.txt
0000000   1   2   3   4   5   6   7   8   9   0   y   o   n   e  \n  \0
0000020  \0  \0  \0  \0   A   B   C   D   E   F   G   H   I   J
0000036
============================================================================
*/
