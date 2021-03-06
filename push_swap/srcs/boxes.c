/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:09:17 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 02:09:21 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_last(t_stack *list)
{
	while (list->next)
		list = list->next;
	return (list->pos);
}

void	choose_move(t_stacklist *list, int ith)
{
	if (check_ith_bit(list->stack_a, ith))
		list->stack_a = ra(list->stack_a);
	else
		pb(&list->stack_a, &list->stack_b);
}

int	sort_boxes(t_stacklist *list, int size, int max_bit, int ith)
{
	int	last;

	last = find_last(list->stack_a);
	while (list->stack_a)
	{
		if (list->stack_a->pos == last)
		{
			choose_move(list, ith);
			list->nb_instr = list->nb_instr + 1;
			break ;
		}
		else
			choose_move(list, ith);
		list->nb_instr = list->nb_instr + 1;
	}
	while (list->stack_b)
	{
		list->nb_instr = list->nb_instr + 1;
		pa(&list->stack_b, &list->stack_a);
	}
	if (ith < max_bit)
		sort_boxes(list, size, max_bit, ith + 1);
	return (1);
}
