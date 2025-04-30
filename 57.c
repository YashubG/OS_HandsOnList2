/* Program Number: 57
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to print system limitations for:
a. Maximum length of arguments in the exec family of functions.
b. Maximum number of simultaneous processes per user ID.
c. Number of clock ticks (jiffies) per second.
d. Maximum number of open files.
e. Size of a page.
f. Total number of pages in physical memory.
g. Number of currently available pages in physical memory
*/
#include <stdio.h>
#include <unistd.h>

int main()
{
    long arg_max = sysconf(_SC_ARG_MAX);
    long child_max = sysconf(_SC_CHILD_MAX);
    long clock_ticks = sysconf(_SC_CLK_TCK);
    long open_max = sysconf(_SC_OPEN_MAX);
    long page_size = sysconf(_SC_PAGESIZE);
    long phys_pages = sysconf(_SC_PHYS_PAGES);
    long avail_pages = sysconf(_SC_AVPHYS_PAGES);

    printf("System Limitations:\n");
    printf("Maximum length of arguments (ARG_MAX): %ld\n", arg_max);
    printf("Maximum number of simultaneous processes per user ID (CHILD_MAX): %ld\n", child_max);
    printf("Number of clock ticks per second (CLK_TCK): %ld\n", clock_ticks);
    printf("Maximum number of open files (OPEN_MAX): %ld\n", open_max);
    printf("Size of a page (PAGESIZE): %ld bytes\n", page_size);
    printf("Total number of pages in physical memory (PHYS_PAGES): %ld\n", phys_pages);
    printf("Number of currently available pages in physical memory (AVPHYS_PAGES): %ld\n", avail_pages);
}
