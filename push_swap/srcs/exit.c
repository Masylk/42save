#include "pushswap.h"

void	free_list(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s;
		s = s->next;
		free(tmp);
	}
}

void	free_stlist(t_stacklist *list)
{
	free_list(list->stack_a);
	free_list(list->stack_b);
	free(list->tab);
}
