/* Program Number: 40
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to print the maximum number of
files that can be opened within a process and the size of a pipe (circular buffer).
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main()
{
    long max_files = sysconf(_SC_OPEN_MAX);      // A POSIX function that retrieves system configuration variables
    long pipe_size = fpathconf(0, _PC_PIPE_BUF); // Another POSIX function that retrieves path-specific configuration variables
    // Using stdin (fd 0) as a reference, we could as well have used
    // stdout (fd 1) or stderr (fd 2) to signify system-wide property and
    // not specific to this process.

    if (max_files != -1)
        printf("Maximum number of open files: %ld\n", max_files);
    else
        printf("Could not determine the maximum number of open files.\n");

    if (pipe_size != -1)
        printf("Size of a pipe (circular buffer): %ld bytes\n", pipe_size);
    else
        printf("Could not determine the size of a pipe.\n");

    return 0;
}