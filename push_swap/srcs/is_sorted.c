/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:09:55 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 02:10:41 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	nb_is_sorted(int *stack, int i, int size)
{
	int	cmp;
	int	index_cmp;

	cmp = stack[i];
	index_cmp = i;
	while (i > 0)
	{
		if (stack[i] > cmp)
			return (0);
		i--;
	}
	i = index_cmp;
	while (i < size)
	{
		if (stack[i] < cmp)
			return (0);
		i++;
	}
	return (1);
}

int	stack_is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
		if (!nb_is_sorted(stack, i++, size))
			return (0);
	return (1);
}
