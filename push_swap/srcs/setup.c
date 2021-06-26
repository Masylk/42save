#include "pushswap.h"

void	set_order(t_stack *stack, int *tab)
{
	int	i;
	int	size;

	size = stack_size(stack);
	while (stack)
	{
		stack->pos = 1;
		i = 0;
		while (i < size)
		{
			if (stack->n > tab[i])
				stack->pos += 1;
			i++;
		}
		stack = stack->next;
	}
}

void	set_order_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j != i && tab[j] == tab[i])
			{
				tab[j] += 1;
				set_order_tab(tab, size);
			}
			j++;
		}
		i++;
	}
}
