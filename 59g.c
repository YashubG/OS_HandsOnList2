/* Program Number: 59
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Write separate programs using the signal system call to catch the
following signals:
g. SIGPROF (using the setitimer system call)
*/

#include <signal.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig)
{
    printf("Caught SIGPROF!\n");
    exit(0); // Exit gracefully after handling
}

int main()
{
    signal(SIGPROF, handler); // Register the signal handler for SIGPROF

    struct itimerval timer;
    timer.it_value.tv_sec = 1; // Initial delay: 1 second
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; // Interval: 0 (Trigger alarm only once)
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1)
        ; // Wait for the signal

    printf("This line will not be reached.\n"); // Will not be reached
}