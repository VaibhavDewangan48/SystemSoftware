/*
============================================================================
Name : 9.c
Author : Vaibhav Dewangan
Description :  Write a program to print the following information about a given file. a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification j. time of last change
Date: 30th August, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    struct stat sb;
   if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
   if (stat(argv[1], &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
   printf("File type:\n");
   printf("a. inode: %ld\n", (long) sb.st_ino);
   printf("b. number of hard links %ld\n", (long) sb.st_nlink);
   printf("c.UID= %ld\n",(long) sb.st_uid); 
   printf("d. GID= %ld\n",(long)sb.st_gid);
   printf("e. File size: %lld bytes\n",(long long) sb.st_size);
   printf("f. block size:  %ld bytes\n",(long) sb.st_blksize);
   printf("g. Number of blocks: %lld\n",(long long) sb.st_blocks);
   printf("h. time of last access: %s", ctime(&sb.st_atime));
   printf("i. time of last modification: %s", ctime(&sb.st_mtime));
   printf("j. time of last change %s", ctime(&sb.st_ctime));
   exit(EXIT_SUCCESS);
}
/* output
==========================================================================
File type:
a. inode: 7097868
b. number of hard links 1
c.UID= 1000
d. GID= 1000
e. File size: 75 bytes
f. block size:  4096 bytes
g. Number of blocks: 8
h. time of last access: Fri Aug 30 15:44:59 2024
i. time of last modification: Fri Aug 30 15:44:59 2024
j. time of last change Fri Aug 30 15:44:59 2024
=========================================================================
*/
