/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:09:41 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 02:10:32 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	size_stack(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int	small_sorts(t_stacklist *list, int size)
{
	if (stack_is_sorted(list->tab, size))
		return (1);
	if (size == 1)
		return (1);
	if (size == 2)
		return (two_sort(list, size));
	else if (size == 3)
		return (trick_sort(list, size));
	else if (size <= 5)
		return (trick_sort_plus(list, size));
	return (0);
}
