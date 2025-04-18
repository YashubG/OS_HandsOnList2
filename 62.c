/* Program Number: 62
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to ignore a SIGINT signal and
then reset it to the default action using the sigaction system call.
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    struct sigaction sa;

    // 1. Ignore SIGINT
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("sigaction (ignore)");
        return 1;
    }
    printf("SIGINT is now being ignored. Press Ctrl+C to test.\n");
    sleep(5);

    // 2. Reset SIGINT to default
    sa.sa_handler = SIG_DFL;
    if (sigaction(SIGINT, &sa, NULL) == -1)
    { // Reusing 'sa'
        perror("sigaction (default)");
        return 1;
    }
    printf("\nSIGINT handler reset to default. Press Ctrl+C test.\n");
    sleep(5);

    printf("Program finished.\n");
}