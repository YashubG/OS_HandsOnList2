/* Program Number: 60
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to ignore a SIGINT signal and
then reset it to the default action using the signal system call
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    // 1. Ignore SIGINT
    if (signal(SIGINT, SIG_IGN) == SIG_ERR)
    {
        perror("signal (ignore)");
        return 1;
    }
    printf("SIGINT is now being ignored. Press Ctrl+C to test.\n");
    sleep(5);

    // 2. Reset SIGINT to its default action
    if (signal(SIGINT, SIG_DFL) == SIG_ERR)
    {
        perror("signal (default)");
        return 1;
    }
    printf("\nSIGINT handler reset to default. Press Ctrl+C now.\n");
    sleep(5);

    printf("Program finished.\n");
}