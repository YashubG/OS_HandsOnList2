/* Program Number: 58
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Simple program to create three threads and
print the IDs of the created threads.
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *thread_function(void *arg)
{
    printf("Thread ID: %ld\n", pthread_self());
}

int main()
{
    pthread_t threads[3];

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&threads[i], NULL, thread_function, NULL); // Create a new thread
        pthread_join(threads[i], NULL);                           // Wait for this thread to finish.
    }

    printf("All threads finished.\n");
}
