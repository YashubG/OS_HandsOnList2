/* Program Number: 59
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Write separate programs using the signal system call to catch the
following signals:
d. SIGALRM (using the alarm system call)
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig)
{
    printf("Caught SIGALRM!\n");
    exit(0); // Exit gracefully after handling
}

int main()
{
    signal(SIGALRM, handler); // Register the signal handler for SIGALRM
    alarm(1);                 // Schedule SIGALRM for 1 second

    while (1)
        ; // Wait for the signal

    printf("This line will not be reached.\n"); // Will not be reached
}