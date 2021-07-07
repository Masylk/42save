#include "pushswap.h"

int	size_stack(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int	small_sorts(t_stacklist *list, int size)
{
	if (size == 2)
		return (two_sort(list, size));
	else if (size == 3)
		return (trick_sort(list, size));
	else if (size <= 5)
		return (trick_sort_plus(list, size));
	return (0);
}
