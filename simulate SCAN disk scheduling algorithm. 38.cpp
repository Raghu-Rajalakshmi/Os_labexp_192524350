#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, seek_time = 0;
    int i, j, temp;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int request_queue[n];

    printf("Enter the disk request queue:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &request_queue[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    /* Sort the request queue */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (request_queue[i] > request_queue[j])
            {
                temp = request_queue[i];
                request_queue[i] = request_queue[j];
                request_queue[j] = temp;
            }
        }
    }

    int pos = 0;

    /* Find first request greater than head */
    while (pos < n && request_queue[pos] < head)
    {
        pos++;
    }

    printf("\nSCAN Disk Scheduling:\n");
    printf("Head Movement: %d", head);

    /* Move towards higher tracks */
    for (i = pos; i < n; i++)
    {
        seek_time += abs(head - request_queue[i]);
        head = request_queue[i];
        printf(" -> %d", head);
    }

    /* Reverse direction */
    for (i = pos - 1; i >= 0; i--)
    {
        seek_time += abs(head - request_queue[i]);
        head = request_queue[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time: %d", seek_time);
    printf("\nAverage Seek Time: %.2f\n",
           (float)seek_time / n);

    return 0;
}
