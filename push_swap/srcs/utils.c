/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:10:20 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 02:10:26 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stack_size(t_stack *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int	*list_to_tab(t_stack *list)
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(int) * (stack_size(list) + 1));
	if (!res)
		return (NULL);
	while (list)
	{
		res[i++] = list->n;
		list = list->next;
	}
	res[i] = 0;
	return (res);
}

int	*poslist_to_tab(t_stack *list)
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(int) * (stack_size(list) + 1));
	if (!res)
		return (NULL);
	while (list)
	{
		res[i++] = list->pos;
		list = list->next;
	}
	res[i] = 0;
	return (res);
}

void	postab_to_list(int *tab, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = tab[i++];
		stack = stack->next;
	}
}
