/* Program Number: 34b
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to execute ls -l | wc using:
b. dup2
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    int p[2];
    pipe(p);

    if (fork() == 0)
    {                  // Child process (wc)
        dup2(p[0], 0); // Redirect stdin to pipe's read end
        close(p[0]);
        close(p[1]);
        execlp("wc", "wc", NULL);
    }
    else
    {                  // Parent process (ls -l)
        dup2(p[1], 1); // Redirect stdout to pipe's write end
        close(p[0]);
        close(p[1]);
        execlp("ls", "ls", "-l", NULL);
    }
}