#include <stdio.h>

int main()
{
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("Philosopher %d is thinking...\n", i);

        printf("Philosopher %d picks up left chopstick.\n", i);

        printf("Philosopher %d picks up right chopstick.\n", i);

        printf("Philosopher %d is eating...\n", i);

        printf("Philosopher %d puts down chopsticks.\n\n", i);
    }

    return 0;
}
