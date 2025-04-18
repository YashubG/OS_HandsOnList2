/* Program Number: 32
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Simple program to send data
from the parent process to the child process
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    int p[2];
    pipe(p);
    if (fork() == 0) // Child
    {
        close(p[1]); // Close write end of pipe in child before reading
        char buf[20];
        read(p[0], buf, 20);
        printf("Child received: %s\n", buf);
        close(p[0]);
    }
    else // Parent
    {
        close(p[0]); // Close read end of pipe in parent before writing
        write(p[1], "Hello from parent!", 18);
        close(p[1]);
    }
}