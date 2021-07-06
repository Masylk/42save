#include "pushswap.h"

int	pb(t_stack *a, t_stack *b)
{
	if (!push(&a, &b))
		return (0);
	ft_printf("pb\n");
	return (1);
}

int	sb(t_stack *b)
{
	if (!swap(b))
		return (0);
	ft_printf("sb\n");
	return (1);
}

int	rb(t_stack *b)
{
	if (!rotate(b))
		return (0);
	ft_printf("rb\n");
	return (1);
}

int	rrb(t_stack *b)
{
	if (!reverse_rotate(b))
		return (0);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack *a, t_stack *b)
{
	if (!rotate(b))
		return (0);
	if (!rotate(a))
		return (0);
	return (1);
}
