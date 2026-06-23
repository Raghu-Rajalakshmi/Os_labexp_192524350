#include <stdio.h>
#include <windows.h>

#define BUFFER_SIZE 5
#define MAX_ITEMS 10

int buffer[BUFFER_SIZE];
int produced_items = 0;
int consumed_items = 0;

void producer()
{
    while (produced_items < MAX_ITEMS)
    {
        int i;

        for (i = 0; i < BUFFER_SIZE; i++)
        {
            if (buffer[i] == 0)
            {
                buffer[i] = produced_items + 1;

                printf("Produced: %d\n", buffer[i]);

                produced_items++;
                break;
            }
        }

        Sleep(1000);
    }
}

void consumer()
{
    while (consumed_items < MAX_ITEMS)
    {
        int i;

        for (i = 0; i < BUFFER_SIZE; i++)
        {
            if (buffer[i] != 0)
            {
                printf("Consumed: %d\n", buffer[i]);

                buffer[i] = 0;
                consumed_items++;
                break;
            }
        }

        Sleep(1500);
    }
}

int main()
{
    printf("Producer-Consumer Problem\n\n");

    while (consumed_items < MAX_ITEMS)
    {
        producer();
        consumer();
    }

    return 0;
}
