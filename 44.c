/* Program Number: 44
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to receive messages from the message queue:
a. With 0 as a flag
b. With IPC_NOWAIT as a flag
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message_buffer
{
    long mtype;
    char mtext[20];
};

int main()
{
    key_t key = ftok(".", 'a');
    int msq_id = msgget(key, IPC_CREAT | 0744); // Create the msg Q if it DNE

    struct message_buffer msg;

    // Fxn def of msgrcv;
    //  ssize_t msgrcv(int __msqid, void *__msgp, size_t __msgsz, long __msgtyp, int __msgflg)

    // a. Receive with flag = 0 (blocking)
    printf("Waiting for message (blocking)...\n");
    if (msgrcv(msq_id, &msg, sizeof(msg.mtext), 1, 0) == -1)
        perror("msgrcv (with flag=0)");
    else
        printf("Received (blocking): %s\n", msg.mtext);

    // b. Receive with flag = IPC_NOWAIT (non-blocking)
    printf("Trying to receive message (non-blocking)...\n");
    if (msgrcv(msq_id, &msg, sizeof(msg.mtext), 1, IPC_NOWAIT) == -1)
        perror("msgrcv (with flag=IPC_NOWAIT)");
    else
        printf("Received (non-blocking): %s\n", msg.mtext);
}
