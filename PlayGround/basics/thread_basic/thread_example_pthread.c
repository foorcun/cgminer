#include <stdio.h>
#include <pthread.h>

//! compile # gcc -o thread_example_pthread thread_example_pthread.c -pthread
//! run # ./thread_example_pthread

// Function to be executed by the thread
void *threadFunction(void *arg)
{
    int threadId = *(int *)arg;

    // Perform some operations in the thread
    printf("Thread %d is running.\n", threadId);

    // Terminate the thread and return a value
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread;
    int parameter = 123; // An example parameter passed to the thread

    // Create a new thread
    if (pthread_create(&thread, NULL, threadFunction, &parameter) != 0)
    {
        fprintf(stderr, "Failed to create a thread.\n");
        return 1;
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    printf("Thread has terminated.\n");

    return 0;
}
