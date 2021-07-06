#include "pushswap.h"

int	init_stacks(t_stacklist *list, char **av)
{
	list->stack_a = arr_to_stack(av + 1);
        if (!list->stack_a)
                return (-1);
        list->stack_b = NULL;
	list->tab = list_to_tab(list->stack_a);
	if (!list->tab)
		return (-1);
	set_order(list->stack_a, list->tab);
	free(list->tab);
	list->tab = poslist_to_tab(list->stack_a);
	if (!list->tab)
		return (-1);
	set_order_tab(list->tab, stack_size(list->stack_a));
	postab_to_list(list->tab, list->stack_a);
	print_stack(list->stack_a);
	return (1);
}
