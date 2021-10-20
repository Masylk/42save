/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:08:03 by mtogbe            #+#    #+#             */
/*   Updated: 2021/10/20 17:08:49 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*new_philo(int id)
{
	t_philo	*res;

	res = malloc(sizeof(t_philo));
	if (!res)
		return (NULL);
	res->id = id;
	res->alive = 1;
	res->hasfork = 1;
	res->eating = 0;
	res->goal = 0;
	res->sleeping = 0;
	res->thinking = 1;
	res->last = 0;
	res->prev_time = 0;
	res->prev_mealtime = 0;
	res->previous = NULL;
	res->next = NULL;
	return (res);
}

t_philo	*get_philo(t_philo *list, int id)
{
	while (list && !list->last)
	{
		if (list->id == id)
			return (list);
		list = list->next;
	}
	if (list->id == id)
		return (list);
	return (NULL);
}

void	add_end(t_philo **list, t_philo *elem)
{
	t_philo	*tmp;

	if (!*list)
	{
		*list = elem;
		(*list)->last = 1;
		(*list)->next = NULL;
		(*list)->previous = NULL;
		return ;
	}
	tmp = *list;
	while (tmp->last == 0)
		tmp = tmp->next;
	tmp->last = 0;
	tmp->next = elem;
	elem->previous = tmp;
	elem->next = *list;
	elem->last = 1;
	(*list)->previous = elem;
}

void	add_start(t_philo **list, t_philo *elem)
{
	t_philo	*tmp;

	tmp = *list;
	if (!tmp)
	{
		*list = elem;
		(*list)->last = 1;
		(*list)->next = NULL;
		(*list)->previous = NULL;
		return ;
	}
	while (tmp->last == 0)
		tmp = tmp->next;
	elem->next = *list;
	elem->previous = tmp;
	*list = elem;
}

void	free_philo(t_philo *list)
{
	t_philo	*stack;

	while (list && !list->last)
	{
		stack = list;
		list = list->next;
		free(stack);
	}
	free(list);
}
