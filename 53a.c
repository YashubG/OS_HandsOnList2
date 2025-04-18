/* Program Number: 53
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Programs for each time domain to set
an interval timer for 10 seconds and 10 microseconds.
a. Use ITIMER_REAL
*/

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    struct itimerval timer;

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    // a. ITIMER_REAL
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1)
    {
        perror("setitimer (REAL)");
        return 1;
    }

    printf("ITIMER_REAL repeating every 10 seconds and 10 microseconds.\n");
    while (1)
        ; // Busy loop to simulate work

    // The process is terminated by the OS upon SIGALRM signal delivery.
}