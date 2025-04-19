/* Program Number: 55
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to set a system resource limit
using the setrlimit system call.
*/

#include <stdio.h>
#include <sys/resource.h>
#include <errno.h>

int main()
{
    struct rlimit new_limit;
    int resource = RLIMIT_NOFILE; // Example: Limit the number of open files

    // Set the new soft limit to 256 and the hard limit to 512
    new_limit.rlim_cur = 1;
    new_limit.rlim_max = 1;

    if (setrlimit(resource, &new_limit) == 0)
        printf("Successfully set the limit for open files.\n");

    // Verify the new limit
    struct rlimit current_limit;
    if (getrlimit(resource, &current_limit) == 0)
    {
        printf("New soft limit: %ld\n", current_limit.rlim_cur);
        printf("New hard limit: %ld\n", current_limit.rlim_max);
    }
}