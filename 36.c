/* Program Number: 36
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to create a FIFO file using:
d. mknod system call
e. mkfifo library function
*/

#include <sys/stat.h>
#include <stdio.h>

int main()
{
    // Create FIFOs
    // d. mknod system call
    if (mknod("myfifo_mknod_c", S_IFIFO | 0666, 0) == -1)
        perror("mknod");

    // e. mkfifo library function
    if (mkfifo("myfifo_mkfifo_c", 0666) == -1)
        perror("mkfifo");
}