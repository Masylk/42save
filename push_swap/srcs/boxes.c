#include "pushswap.h"

int	sort_boxes(t_stacklist *list, int size, int max_bit, int ith)
{
	int	head;
	int	pushed;

	pushed = 1;
	head = -1;
//	print_stack(list->stack_a);
	while (list->stack_a->pos != head)
	{
		if (check_ith_bit(list->stack_a, ith) && pushed)
		{
			if (pushed)
			{
				head = list->stack_a->pos;
				pushed = 0;
			}
			ra(list->stack_a);
			printf("oui");
		}
		else
		{
			printf("non");
			pb(list->stack_a, list->stack_b);
			pushed = 1;
		}
		printf(" %d ", list->stack_a->pos);
		break ;
	}
//	print_stack(list->stack_a);
	print_stack(list->stack_b);
	return (1);
	while (list->stack_b)
		pa(list->stack_b, list->stack_a);
	if (ith <= max_bit)
		sort_boxes(list, size, max_bit, ith++);
	return (1);
}
