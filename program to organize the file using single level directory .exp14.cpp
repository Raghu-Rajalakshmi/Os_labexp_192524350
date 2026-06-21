#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void copy()
{
    const char *source_file =
        "C:/Users/itssk/OneDrive/Desktop/sasi.txt";

    const char *destination_file =
        "C:/Users/itssk/OneDrive/Desktop/sk.txt";

    int source_fd = open(source_file, O_RDONLY);

    int dest_fd = open(destination_file,
                       O_WRONLY | O_CREAT | O_TRUNC,
                       0666);

    char buffer[BUFFER_SIZE];
    int bytesRead;

    if (source_fd == -1 || dest_fd == -1)
    {
        printf("Error opening file.\n");
        return;
    }

    while ((bytesRead = read(source_fd,
                             buffer,
                             BUFFER_SIZE)) > 0)
    {
        write(dest_fd, buffer, bytesRead);
    }

    close(source_fd);
    close(dest_fd);

    printf("File copied successfully.\n");
}

void create()
{
    FILE *fp;

    fp = fopen(
        "C:/Users/itssk/OneDrive/Desktop/sasi.txt",
        "w");

    if (fp == NULL)
    {
        printf("File cannot be created.\n");
    }
    else
    {
        printf("File created successfully.\n");
        fclose(fp);
    }
}

void deleteFile()
{
    if (remove(
            "C:/Users/itssk/OneDrive/Desktop/sasi.txt") == 0)
    {
        printf("File deleted successfully.\n");
    }
    else
    {
        printf("Unable to delete file.\n");
    }
}

int main()
{
    int n;

    printf("1. Create\n");
    printf("2. Copy\n");
    printf("3. Delete\n");
    printf("Enter your choice: ");

    scanf("%d", &n);

    switch (n)
    {
        case 1:
            create();
            break;

        case 2:
            copy();
            break;

        case 3:
            deleteFile();
            break;

        default:
            printf("Invalid choice.");
    }

    return 0;
}
