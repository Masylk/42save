#include <stdlib.h>
#include <stdio.h>

int    ft_malloc(void **ptr, size_t size, int n)
{
    *ptr = malloc(size * n);
    if (!(*ptr))
        return (0);
    return (1);
}

int main()
{
    char    **tab;
    int     row;
    int     col;
    int     i;
    int     j;

    row = 4;
    col = 5;
    if (!(ft_malloc((void *)&tab, sizeof(char*), row + 1)))
        return (0);
    tab[row] = NULL;
    while (i < row)
    {
        j = 0;
        if (!(ft_malloc((void *)&tab[i], sizeof(char), col + 1)))
            return (0);
        while (j < col)
        {
            tab[i][j] = 'a';
            j = j + 1;
        }
        tab[i][j] = '\0';
        i = i + 1;
    }
    i = 0;
    while (tab[i])
    {
        printf("%s\n", tab[i++]);
    }
    
}
