#include <stdio.h>
#include <string.h>

char shared_memory[1024];

int main()
{
    /* Write data to shared memory */
    strcpy(shared_memory, "Hello, shared memory!");

    /* Read data from shared memory */
    printf("Data written to shared memory: %s\n", shared_memory);

    return 0;
}
