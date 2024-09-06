/*
============================================================================
Name : 6.c
Author : Vaibhav Dewangan
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 24th Aug, 2024.
============================================================================
*/

#include <unistd.h>

int main() {
char buffer[1024];
ssize_t bytesRead;

// Read input from STDIN
while ((bytesRead = read(0, buffer, sizeof(buffer))) > 0) {
// Write the same input to STDOUT
write(1, buffer, bytesRead);
}

return 0;
}

/*
=========================================================================
hello
hello
everyone
everyone
666
666
=========================================================================
then click ctrl+D to stop
*/
