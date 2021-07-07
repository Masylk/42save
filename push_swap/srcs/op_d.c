#include "pushswap.h"

int	pb(t_stack **a, t_stack **b)
{
	if (!push(a, b))
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

t_stack	*rb(t_stack *b)
{
	b = rotate(b);
	if (!b)
		return (b);
	ft_printf("rb\n");
	return (b);
}

t_stack	*rrb(t_stack *b)
{
	b = reverse_rotate(b);
	if (!b)
		return (b);
	ft_printf("rrb\n");
	return (b);
}

//finir correctement avec stacklist
t_stack	*rrr(t_stack *a, t_stack *b)
{
	b = rotate(b);
	if (!b)
		return (b);
	a = rotate(a);
	if (!a)
		return (a);
	return (b);
}
