/* Program Number: 61
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Write separate programs using the sigaction
system call to catch the following signals:
b. SIGINT
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigint_handler(int signum)
{
    printf("\nCaught SIGINT (%d).\n", signum);
    exit(0); // Exit gracefully after handling
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }

    printf("Press Ctrl+C to trigger SIGINT...\n");
    while (1)
        ; // Waiting for Ctrl+C

    printf("This line should not be printed.\n"); // This won't be executed
}
