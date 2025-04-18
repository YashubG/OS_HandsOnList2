/* Program Number: 63
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to create an orphan process. Utilize
the kill system call to send a SIGKILL signal from the child process to the parent
process
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    if (fork() == 0)
    { // Child process
        printf("Child process (PID: %d) started.\n", getpid());
        printf("Child sending SIGKILL to parent (PPID: %d)...\n", getppid());
        kill(getppid(), SIGKILL); // SIGKILL sent
        sleep(1);
        printf("Child exiting.\n");
    }
    else
    { // Parent process
        printf("Parent process (PID: %d) started.\n", getpid());
        sleep(.1);                   // Parent will exit before the child, making the child an orphan
        printf("Parent exiting.\n"); // This line will not be reached.
    }
}