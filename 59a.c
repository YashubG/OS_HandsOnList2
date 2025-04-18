/* Program Number: 59
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Write separate programs using the signal system call to catch the
following signals:
a. SIGSEGV
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigsegv(int signum)
{
    printf("Caught SIGSEGV (Segmentation Fault)!\n");
    exit(0); // Exit immediately after handling the signal
}

int main()
{
    // Register the signal handler for SIGSEGV
    signal(SIGSEGV, handle_sigsegv);
    printf("Attempting to cause a segmentation fault...\n");

    // This line will intentionally cause a segmentation fault
    int *ptr = NULL;
    *ptr = 10;

    printf("This line will not be reached.\n"); // This won't be executed
}