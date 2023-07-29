/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:09:48 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 02:10:40 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	init_stacks(t_stacklist *list, char **av)
{
	list->nb_instr = 0;
	list->stack_a = arr_to_stack(av);
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
	return (1);
}
