#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int source, dest;
    char buffer[1024];
    int bytes;

    source = open("source.txt", O_RDONLY);

    if (source < 0)
    {
        printf("Cannot open source file\n");
        return 1;
    }

    dest = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while ((bytes = read(source, buffer, sizeof(buffer))) > 0)
    {
        write(dest, buffer, bytes);
    }

    close(source);
    close(dest);

    printf("File copied successfully.\n");

    return 0;
}