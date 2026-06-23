#include <stdio.h>

int counter = 0;

void threadFunction()
{
    int i;

    for (i = 0; i < 1000000; i++)
    {
        counter++;
    }
}

int main()
{
    /* Simulate two threads */
    threadFunction();
    threadFunction();

    printf("Final counter value: %d\n", counter);

    return 0;
}
