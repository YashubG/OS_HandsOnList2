/* Program Number: 64
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Create two programs: the first program awaits the
SIGSTOP signal, while the second program sends the signal using the kill system call.
Determine whether the first program successfully catches the signal or not.

Program 2.. THIS PROGRAM SENDS THE SIGSTOP SIGNAL
*/

// NOTE: Run Program 1(64_predator.c) before running this.

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
    else
    {
        pid_t pid_to_send = atoi(argv[1]);

        if (kill(pid_to_send, SIGSTOP) == -1)
            perror("kill");
        else
            printf("SIGSTOP signal sent to process with PID %d\nNote that the signal is not handled but stops this program.\n", pid_to_send);
    }
}