/* Program Number: 59
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Write separate programs using the signal system call to catch the
following signals:
c. SIGFPE
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigfpe(int signum)
{
    printf("Caught SIGFPE!\n");
    exit(0); // Exit gracefully after handling
}

int main()
{
    signal(SIGFPE, handle_sigfpe); // Register the signal handler for SIGFPE
    printf("Attempting to cause a floating point error...\n");

    int a = 10 / 0; // Will cause a floating point error

    printf("This line will not be reached.\n"); // Will not be reached
}