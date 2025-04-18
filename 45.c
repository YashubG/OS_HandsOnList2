/* Program Number: 45
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to change the existing
message queue permissions using the msqid_ds structure.
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

int main()
{
    key_t key = ftok(".", 'a');
    int msq_id = msgget(key, IPC_CREAT | 0744); // Create the msg Q if it DNE

    struct msqid_ds buf;

    // Get current settings
    if (msgctl(msq_id, IPC_STAT, &buf) == -1)
        perror("msgctl (with cmd=IPC_STAT)");
    else
    {
        // Change permissions: for example, set to 0700
        buf.msg_perm.mode = 0700;

        // Apply the new settings
        if (msgctl(msq_id, IPC_SET, &buf) == -1)
            perror("msgctl - IPC_SET");
        else
            printf("Permissions updated successfully. Check using \"ipcs -q\"\n");
    }
}