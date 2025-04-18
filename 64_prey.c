/* Program Number: 64
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Create two programs: the first program awaits the
SIGSTOP signal, while the second program sends the signal using the kill system call.
Determine whether the first program successfully catches the signal or not.

Program 1.. THIS PROGRAM RECEIVES THE SIGSTOP SIGNAL
*/
// Program 1: await_sigstop.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signum)
{
    printf("Signal %d caught!\n", signum);
    exit(0); // Exit gracefulluy
}

int main()
{
    printf("PID of this process: %d\n", getpid());

    // Set up a signal handler for SIGSTOP
    signal(SIGSTOP, signal_handler);

    printf("Waiting for SIGSTOP...\n");
    while (1)
        ; // Waiting for the SIGSTOP
}