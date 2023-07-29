/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:10:11 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 02:10:47 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_ith_bit(t_stack *s, int i)
{
	return (((s->pos) >> i) & 1);
}

int	check_max_bit(t_stack *s)
{
	int	i;
	int	max;

	max = 0;
	while (s)
	{
		i = 0;
		while (i < 32)
		{
			if (check_ith_bit(s, i) && i > max)
				max = i;
			i++;
		}	
		s = s->next;
	}
	return (max);
}

int	rd_sort(t_stacklist *list, int size)
{
	int	max_bit;

	max_bit = check_max_bit(list->stack_a);
	if (!max_bit)
		return (1);
	sort_boxes(list, size, max_bit, 0);
	return (1);
}

int	rd_sort_stack(t_stacklist *list, int size)
{
	if (stack_is_sorted(list->tab, size))
		return (1);
	else
		rd_sort(list, size);
	free(list->tab);
	list->tab = NULL;
	return (1);
}
