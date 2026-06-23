#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to represent a block */
struct Block
{
    char data[256];
    struct Block *next;
};

int main()
{
    struct Block *firstBlock = NULL;
    struct Block *lastBlock = NULL;

    int blockCount = 0;
    int blockNumber;
    char data[256];
    char choice;

    printf("Linked Allocation Simulation\n");

    while (1)
    {
        printf("\nEnter 'W' to write a block, "
               "'R' to read a block, "
               "or 'Q' to quit: ");

        scanf(" %c", &choice);

        if (choice == 'Q' || choice == 'q')
        {
            break;
        }

        if (choice == 'W' || choice == 'w')
        {
            printf("Enter data for the block: ");
            scanf(" %[^\n]", data);

            /* Create a new block */
            struct Block *newBlock;

            newBlock = (struct Block *)
                       malloc(sizeof(struct Block));

            strcpy(newBlock->data, data);

            newBlock->next = NULL;

            if (blockCount == 0)
            {
                firstBlock = newBlock;
                lastBlock = newBlock;
            }
            else
            {
                lastBlock->next = newBlock;
                lastBlock = newBlock;
            }

            blockCount++;

            printf("Block stored successfully.\n");
        }
        else if (choice == 'R' || choice == 'r')
        {
            printf("Enter block number to read (1-%d): ",
                   blockCount);

            scanf("%d", &blockNumber);

            if (blockNumber < 1 ||
                blockNumber > blockCount)
            {
                printf("Invalid block number.\n");
            }
            else
            {
                struct Block *currentBlock = firstBlock;
                int i;

                for (i = 1; i < blockNumber; i++)
                {
                    currentBlock =
                        currentBlock->next;
                }

                printf("Block %d Data: %s\n",
                       blockNumber,
                       currentBlock->data);
            }
        }
    }

    /* Free allocated memory */
    {
        struct Block *currentBlock = firstBlock;

        while (currentBlock != NULL)
        {
            struct Block *nextBlock =
                currentBlock->next;

            free(currentBlock);

            currentBlock = nextBlock;
        }
    }

    return 0;
}
