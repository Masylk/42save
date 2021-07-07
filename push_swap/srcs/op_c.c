#include "pushswap.h"

int	pa(t_stack **b, t_stack **a)
{
	if (!push(b, a))
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

t_stack	*ra(t_stack *a)
{
	a = rotate(a);
	if (!a)
		return (a);
	ft_printf("ra\n");
	return (a);
}

t_stack	*rra(t_stack *a)
{
	a = reverse_rotate(a);
	if (!a)
		return (a);
	ft_printf("rra\n");
	return (a);
}
