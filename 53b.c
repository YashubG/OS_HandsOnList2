/* Program Number: 53
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Programs for each time domain to set
an interval timer for 10 seconds and 10 microseconds.
b. Use ITIMER_VIRTUAL
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

    // b. ITIMER_VIRTUAL
    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1)
    {
        perror("setitimer (VIRTUAL)");
        return 1;
    }

    printf("ITIMER_VIRTUAL repeating every 10 seconds and 10 microseconds of process time.\n");
    while (1)
        ;
}