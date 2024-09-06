/*
============================================================================
Name : 8.c
Author : Vaibhav Dewangan
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached
Date: 26th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file; 
    char line[256]; 
    const char *filename = "demo.txt"; 

    
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    
    while (fgets(line, sizeof(line), file)) {
        
        printf("%s", line);
    }

    
    if (fclose(file) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


/*  output
============================================================
Hi
============================================================
*/
