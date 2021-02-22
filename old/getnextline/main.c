#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
    int fd;
    int ret;
    char    *line;

    if (ac < 2)
        return (0);
    fd = open(av[1], O_RDONLY);
    while ((ret = get_next_line(fd, &line)))
    {
        printf("line : %s ret : %d\n", line, ret);
        free(line);
    }
    printf("line : %s ret : %d\n", line, ret);
    free(line);
}