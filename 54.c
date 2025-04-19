/* Program Number: 54
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to print system resource limits using the
getrlimit system call.
*/

#include <stdio.h>
#include <sys/resource.h>

int main()
{
    struct rlimit limit;

    // Real-time non-blocking time (-R)
    if (getrlimit(RLIMIT_RTTIME, &limit) == 0)
        printf("RLIMIT_RTTIME: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    // Core file size (-c)
    if (getrlimit(RLIMIT_CORE, &limit) == 0)
        printf("RLIMIT_CORE: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    // Data seg size (-d)
    if (getrlimit(RLIMIT_DATA, &limit) == 0)
        printf("RLIMIT_DATA: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    //  Scheduling priority (-e)
    if (getrlimit(RLIMIT_NICE, &limit) == 0)
        printf("RLIMIT_NICE: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    // File size (-f)
    if (getrlimit(RLIMIT_FSIZE, &limit) == 0)
        printf("RLIMIT_FSIZE: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    //  Pending signals (-i)
    if (getrlimit(RLIMIT_SIGPENDING, &limit) == 0)
        printf("RLIMIT_SIGPENDING: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    // Max locked memory (-l)
    if (getrlimit(RLIMIT_MEMLOCK, &limit) == 0)
        printf("RLIMIT_MEMLOCK: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    // Max memory size (-m)
    if (getrlimit(RLIMIT_AS, &limit) == 0)
        printf("RLIMIT_AS: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    // Open files (-n)
    if (getrlimit(RLIMIT_NOFILE, &limit) == 0)
        printf("RLIMIT_NOFILE: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    //  POSIX message queues (-q)
    if (getrlimit(RLIMIT_MSGQUEUE, &limit) == 0)
        printf("RLIMIT_MSGQUEUE: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    //  Real-time priority (-r)
    if (getrlimit(RLIMIT_RTPRIO, &limit) == 0)
        printf("RLIMIT_RTPRIO: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    // Stack size (-s)
    if (getrlimit(RLIMIT_STACK, &limit) == 0)
        printf("RLIMIT_STACK: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    // CPU time (-t)
    if (getrlimit(RLIMIT_CPU, &limit) == 0)
        printf("RLIMIT_CPU: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    //  Max user processes (-u)
    if (getrlimit(RLIMIT_NPROC, &limit) == 0)
        printf("RLIMIT_NPROC: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    // Virtual memory (-v)
    if (getrlimit(RLIMIT_AS, &limit) == 0)
        printf("RLIMIT_AS: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);

    //  File locks (-x)
    if (getrlimit(RLIMIT_LOCKS, &limit) == 0)
        printf("RLIMIT_LOCKS: soft = %ld, hard = %ld\n", limit.rlim_cur, limit.rlim_max);
}