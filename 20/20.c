/*
============================================================================
Name : 20.c
Author : Vaibhav Dewangan
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 27th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int priority = 10;  // New priority value

    // Get the current priority
    int old_priority = getpriority(PRIO_PROCESS, 0);
    printf("Old priority: %d\n", old_priority);

    // Set the new priority
    if (setpriority(PRIO_PROCESS, 0, priority) == -1) {
        perror("setpriority");
        return 1;
    }

    // Get the updated priority
    int new_priority = nice(5);
    printf("New priority: %d\n", new_priority);

    sleep(5);

    return 0;
}
/*
output
=========================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/handson/problem20$ ./20 
Old priority: 0
New priority: 15
=========================================================================
*/
