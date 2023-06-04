#include <stdio.h>
#include <pthread.h>

//! compile # gcc -o thread_example_pthread thread_example_pthread.c -pthread
//! run # ./thread_example_pthread


// if pthread installed or not check


#ifdef PTHREAD_H
    printf("The pthread.h library is installed.\n");
    // Rest of your code using the library
#else
    printf("Warning: The pthread.h library is not installed.\n");
    // Handle the situation when the library is not installed
#endif



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
