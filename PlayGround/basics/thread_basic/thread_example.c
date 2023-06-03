#include <stdio.h>
#include <windows.h>

// Function to be executed by the thread
DWORD WINAPI threadFunction(LPVOID lpParam)
{
    // Cast the parameter back to the desired type
    int threadId = *(int *)lpParam;

    // Perform some operations in the thread
    printf("Thread %d is running.\n", threadId);

    // Terminate the thread and return a value
    return 0;
}

int main()
{
    HANDLE hThread;
    DWORD threadId;
    int parameter = 123; // An example parameter passed to the thread

    // Create a new thread
    hThread = CreateThread(NULL, 0, threadFunction, &parameter, 0, &threadId);
    if (hThread == NULL)
    {
        fprintf(stderr, "Failed to create a thread.\n");
        return 1;
    }

    // Wait for the thread to finish
    WaitForSingleObject(hThread, INFINITE);

    // Close the thread handle
    CloseHandle(hThread);

    printf("Thread %d has terminated.\n", threadId);

    return 0;
}
