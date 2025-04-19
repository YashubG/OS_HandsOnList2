/* Program Number: 56
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to measure the time taken to
execute 100 getppid() system calls using a time stamp counter.
*/
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

// rdtsc stands for read Time Stamp Counter (TSC)
unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc" : "=A"(dst));
    return dst;
}

int main()
{
    unsigned long long start = rdtsc();

    for (int i = 0; i < 100; i++)
        getppid(); // Call the getppid() system call 100 times

    unsigned long long end = rdtsc();

    printf("Time taken for 100 getppid() calls: %lld CPU cycles\n", (end - start)); // %llu: format specifier for unsigned long long integer
}