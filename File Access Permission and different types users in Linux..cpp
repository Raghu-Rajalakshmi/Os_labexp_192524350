#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[] = "file.txt";

    if (system("attrib +R file.txt") == 0)
    {
        printf("File changed to Read Only.\n");
    }
    else
    {
        printf("Unable to change file attributes.\n");
    }

    return 0;
}
