#include "libft.h"

int    ft_malloc(void **ptr, size_t size, int n)
{
    *ptr = malloc(size * n);
    if (!ptr)
        return (0);
    return (1);
}