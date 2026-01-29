#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    char    *line = malloc(10000); // Large buffer for simplicity
    char    buffer;
    int     i = 0;
    int     rd;

    if (fd < 0 || !line)
        return (NULL);

    while ((rd = read(fd, &buffer, 1)) > 0)
    {
        line[i++] = buffer;
        if (buffer == '\n')
            break;
    }

    if (rd <= 0 && i == 0)
    {
        free(line);
        return (NULL);
    }

    line[i] = '\0';
    return (line);
}