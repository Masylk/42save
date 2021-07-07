#include "pushswap.h"

int	is_biggest(t_stack *s, int i)
{
	while (s)
	{
		if (i < s->pos)
			return (0);
		s = s->next;
	}
	return (1);
}

int	is_smallest(t_stack *s, int i)
{
	while (s)
	{
		if (i > s->pos)
			return (0);
		s = s->next;
	}
	return (1);
}


int	two_sort(t_stacklist *list, int size)
{
	t_stack	*a;

	a = list->stack_a;
	if (!stack_is_sorted(list->tab, size))
		sa(a);
	return (1);
}

int	trick_sort(t_stacklist *list, int size)
{
	int	*tmp;

	tmp = list->tab;
	while (!stack_is_sorted(tmp, size))
	{
		if (list->stack_a->pos == list->stack_a->next->pos + 1)
			sa(list->stack_a);
		else if (is_biggest(list->stack_a, list->stack_a->pos))
			list->stack_a = ra(list->stack_a);
		else if (is_biggest(list->stack_a, list->stack_a->next->pos))
			list->stack_a = rra(list->stack_a);
		free(tmp);
		tmp = list_to_tab(list->stack_a);
	}
	return (1);
}

int	trick_sort_plus(t_stacklist *list, int size)
{
	while (stack_size(list->stack_a) != 3)
	{
		if (is_biggest(list->stack_a, list->stack_a->pos))
			pb(&list->stack_a, &list->stack_b);
		else if (is_smallest(list->stack_a, list->stack_a->pos))
			pb(&list->stack_a, &list->stack_b);
		else
			list->stack_a = ra(list->stack_a);
	}
	trick_sort(list, stack_size(list->stack_a));
	while (stack_size(list->stack_a) != size)
	{
		pa(&list->stack_b, &list->stack_a);
		if (is_biggest(list->stack_a, list->stack_a->pos))
			list->stack_a = ra(list->stack_a);
	}
	return (1);
}
