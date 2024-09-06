/*
============================================================================
Name : 19.c
Author : Vaibhav Dewangan
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

static __inline__ unsigned long long rdtsc(void) {
    unsigned hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;
    
    // Read TSC before getpid()
    start = rdtsc();
    
    // Call getpid()
    pid_t pid = getpid();
    
    // Read TSC after getpid()
    end = rdtsc();
    
    // Calculate the difference in CPU cycles
    printf("PID: %d\n", pid);
    printf("Time taken by getpid() in CPU cycles: %llu\n", end - start);
    
    return 0;
}
/*
output 
=========================================================================
PID: 52962
Time taken by getpid() in CPU cycles: 15992
=========================================================================
*/
