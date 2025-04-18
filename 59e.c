/* Program Number: 59
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Write separate programs using the signal system call to catch the
following signals:
e. SIGALRM (using the setitimer system call)
*/

#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int sig)
{
    printf("Caught SIGALRM!\n");
    exit(0); // Exit gracefully after handling
}

int main()
{
    signal(SIGALRM, handler); // Register the signal handler for SIGALRM

    struct itimerval timer;
    timer.it_value.tv_sec = 1; // Initial delay: 1 second
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; // Interval: 0 (Trigger alarm only once)
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1)
        ; // Wait for the signal

    printf("This line will not be reached.\n"); // Will not be reached
}