/* Program Number: 35
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to find the total number of
directories in the present working directory using ls -l | grep ^d | wc. Implement the
solution using only dup2.
*/

// We have (parent -> [p1] -> child -> [p2] -> grandchild -> [stdout])

#include <stdio.h>
#include <unistd.h>

int main()
{
    int p1[2];
    pipe(p1);

    if (fork() == 0)
    {
        int p2[2];
        pipe(p2);

        if (fork() == 0)
        {                   // Grandchild process (wc)
            dup2(p2[0], 0); // Redirect stdin to pipe 2's read end.
            close(p1[0]);   // Close all pipe ends since those needed have already been duplicated
            close(p1[1]);
            close(p2[0]);
            close(p2[1]);
            execlp("wc", "wc", NULL);
        }
        else // Child process (grep ^d)
        {
            dup2(p1[0], 0); // Redirect stdin to pipe 1's read end.
            dup2(p2[1], 1); // Redirect stdout to pipe 2's write end.
            close(p1[0]);   // Close all pipe ends since those needed have already been duplicated
            close(p1[1]);
            close(p2[0]);
            close(p2[1]);
            execlp("grep", "grep", "^d", NULL);
        }
    }

    else
    {                   // Parent process (ls -l)
        dup2(p1[1], 1); // Redirect stdout to pipe's write end
        close(p1[0]);
        close(p1[1]);
        execlp("ls", "ls", "-l", NULL);
    }
}