#include "pushswap.h"

int	pa(t_stack *b, t_stack *a)
{
	if (!push(&b, &a))
		return (0);
	ft_printf("pa\n");
	return (1);
}

int	sa(t_stack *a)
{
	if (!swap(a))
		return (0);
	ft_printf("sa\n");
	return (1);
}

int	ra(t_stack *a)
{
	if (!rotate(a))
		return (0);
	ft_printf("ra\n");
	return (1);
}

int	rra(t_stack *a)
{
	if (!reverse_rotate(a))
		return (0);
	ft_printf("rra\n");
	return (1);
}
