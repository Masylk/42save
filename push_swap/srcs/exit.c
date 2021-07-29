/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:09:45 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/30 00:02:37 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	free_tab(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i++]);
	}
	free(arg);
}

void	free_stlist(t_stacklist *list, char **arg)
{
	free_list(list->stack_a);
	free_list(list->stack_b);
	free_tab(arg);
}
