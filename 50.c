/* Program Number: 50
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program that intentionally induces a deadlock scenario using
semaphores.
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1, sem2;

void *threadA(void *arg)
{
    // Wait to acquire semaphore sem1
    sem_wait(&sem1);
    printf("Thread A: Acquired semaphore 1.\n");
    // Wait to acquire semaphore sem2 -> Infinite wait since threadB holds sem2
    // Lines after this won't be executed.

    sem_wait(&sem2);
    printf("Thread A: Acquired semaphore 2.\n");
    sem_post(&sem2);
    sem_post(&sem1);
    pthread_exit(NULL);
}

void *threadB(void *arg)
{
    // Wait to acquire semaphore sem2
    sem_wait(&sem2);
    printf("Thread B: Acquired semaphore 2.\n");
    // Wait to acquire semaphore sem1 -> Infinite wait since threadB holds sem1
    // Lines after this won't be executed.

    sem_wait(&sem1);
    printf("Thread B: Acquired semaphore 1.\n");
    sem_post(&sem1);
    sem_post(&sem2);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread_id1, thread_id2;

    // Initialise two binary semaphores
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 1);

    // Create two threads
    pthread_create(&thread_id1, NULL, threadA, NULL);
    pthread_create(&thread_id2, NULL, threadB, NULL);

    // Lines after this won't be executed.

    // Wait for those threads to join the main thread
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    // Destroy the semaphores after use
    sem_destroy(&sem1);
    sem_destroy(&sem2);

    printf("Main thread exiting.\n");
}