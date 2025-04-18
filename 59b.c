/* Program Number: 59
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Write separate programs using the signal system call to catch the
following signals:
b. SIGINT
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigint(int signum)
{
    printf("\nCaught SIGINT (Ctrl+C)!\n");
    exit(0); // Exit gracefully after handling
}

int main()
{
    signal(SIGINT, handle_sigint); // Register the signal handler for SIGINT
    printf("Waiting for Ctrl+C...\n");

    while (1)
        ; // Keep the program running

    printf("This line will not be reached.\n"); // Will not be reached
}