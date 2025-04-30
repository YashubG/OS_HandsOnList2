/* Program Number: 43
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to send messages to the
message queue. Check using $ipcs -q
*/
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message_buffer
{
    long mtype;
    char mtext[20];
};

int main()
{
    key_t key = ftok(".", 'a');
    int msq_id = msgget(key, IPC_CREAT | 0777); // Create the msg Q if it DNE

    struct message_buffer msg = {1, "Hello World!"};

    // Fxn def of msgsnd:
    //  int msgsnd(int __msqid, const void *__msgp, size_t __msgsz, int __msgflg)
    msgsnd(msq_id, &msg, sizeof(msg.mtext), 0);

    printf("Message sent. Now check by entering the following into the terminal: \"ipcs -q\"\n");
}