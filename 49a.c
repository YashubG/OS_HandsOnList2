/* Program Number: 49
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to implement a semaphore to
protect any critical section:
a. Rewrite the ticket number creation program using a semaphore
*/

/* a. Program to simulate online ticket
reservation with the implementation of a write lock. Write one program to open a
file, store a ticket number, and exit. Write a separate program to open the file,
implement a write lock, read the ticket number, increment the number, print the new
ticket number, and then close the file.

This program intializes the ticket file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>

int Initializer_Program()
{
    FILE *fp = fopen("Ticket File.txt", "w");
    if (fp == NULL)
    {
        perror("Error opening Ticket file for initialization.");
        return 1;
    }

    printf("Enter your ticket number:\n");
    int ticketNo;
    scanf("%d", &ticketNo);
    getchar(); // To consume the \n character
    fprintf(fp, "%d", ticketNo);
    fclose(fp);

    printf("Ticket file initialized.\n");

    return 0;
}

/*
This program reserves the ticket, i.e.implements the lock and increments the ticket number
*/
int main()
{
    // Firstly, call the initializer program to open the ticket file
    //  and store the initial ticket number.
    if (Initializer_Program())
        return 1;

    printf("\nDONE\n");

    // Create and initialise a binary semaphore
    sem_t *mySemaphore = sem_open("ticketSemaphore.sem", O_CREAT, 0666, 1);
    if (mySemaphore == SEM_FAILED)
    {
        perror("sem_open failed");
        exit(EXIT_FAILURE);
    }
    sem_init(mySemaphore, 0, 1); // Initialise the semaphore

    // Open the ticket file again
    int fd = open("Ticket File.txt", O_RDWR);

    printf("%d: Trying to acquire (semaphore) lock...\n", getpid());

    // Acquire the semaphore (wait if it's locked)
    if (sem_wait(mySemaphore) == -1)
    {
        perror("sem_wait failed");
        sem_close(mySemaphore);
        exit(EXIT_FAILURE);
    }

    printf("%d: (Semaphore) Lock acquired.\n", getpid());

    // Read and print the ticket number
    char ticketNo[100];
    read(fd, ticketNo, 100);
    int ticket = atoi(ticketNo);
    printf("Reserving ticket: %d\n", ticket);

    printf("Ticket %d reserved successfully\n", ticket);

    // Increment the ticket no(Overwrite the file contents)
    ticket++;
    char newTicketNo[100];
    sprintf(newTicketNo, "%d", ticket);
    lseek(fd, 0, SEEK_SET);
    write(fd, newTicketNo, strlen(newTicketNo));

    // Release the semaphore
    printf("Press enter to continue...\n");
    getchar();
    if (sem_post(mySemaphore) == -1)
        perror("sem_post failed");
    printf("New ticket written successfuly\n");
    // Close the semaphore
    if (sem_close(mySemaphore) == -1)
        perror("sem_close failed");
    if (sem_unlink("ticketSemaphore.sem") == -1)
        perror("sem_unlink failed");

    printf("%d: Finished.\n", getpid());

    // Print the new ticket number
    printf("New ticket number: %d\n", ticket);

    // Close the file
    close(fd);
}