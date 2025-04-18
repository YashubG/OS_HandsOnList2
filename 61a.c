/* Program Number: 61
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Write separate programs using the sigaction
system call to catch the following signals:
a. SIGSEGV
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int signum)
{
    printf("Caught SIGSEGV (%d).\n", signum);
    exit(0); // Exit gracefully after handling
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = sigsegv_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGSEGV, &sa, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }

    printf("Attempting to cause a segmentation fault...\n");
    // This line will intentionally cause a segmentation fault
    int *ptr = NULL;
    *ptr = 10;

    printf("This line should not be printed.\n"); // This won't be executed
}