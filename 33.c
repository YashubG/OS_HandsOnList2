/* Program Number: 33
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to send and receive data between the
parent and child processes using two-way communication.
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    int p1[2], p2[2];
    pipe(p1);
    pipe(p2);

    if (fork() == 0) // Child
    {
        close(p1[0]); // Close unrequired pipe ends in child
        close(p2[1]);

        char buf[20];
        write(p1[1], "Hello from child!", 17);
        read(p2[0], buf, 20);
        printf("Child received: %s\n", buf);

        close(p1[1]);
        close(p2[0]);
    }
    else // Parent
    {
        close(p1[1]); // Close unrequired pipe ends in parent
        close(p2[0]);

        char buf[20];
        read(p1[0], buf, 20);
        write(p2[1], "Hello from parent!", 18);
        printf("Parent received: %s\n", buf);

        close(p1[0]);
        close(p2[1]);
    }
}