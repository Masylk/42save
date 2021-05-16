/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:57:48 by mtogbe            #+#    #+#             */
/*   Updated: 2021/05/16 18:23:01 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calloc.h"

void	free_part_start(void *ptr, t_cal **list)
{
	t_cal	*tmp;

	if (*list && (*list)->content == ptr)
	{
		printf("in start\n");
		tmp = *list;
		if (!((*list)->next))
			*list = NULL;
		free(tmp->content);
		tmp->content = NULL;
		free(tmp);
		tmp = NULL;
	}
	if ((*list)->next)
	{
		*list = (*list)->next;
	}
}

void	free_part_end(void *ptr, t_cal **list)
{
	t_cal *tmp;

	if (list && *list && (*list)->content == ptr)
	{
		tmp = *list;
		printf("in end\n");
		free(tmp->content);
		tmp->content = NULL;
		free(tmp);
		tmp = NULL;
	}
}

void	free_part(void *ptr, t_cal **lst)
{
	t_cal	*tmp;
	t_cal	*head;

	head = lst;
	free_part_start(ptr, lst);
	printf("head : %p\n", (*head)->content);
	while (lst && *lst  && (*lst)->next)
	{
		printf("inmid\n");
		if ((*lst)->next->content == ptr)
		{
			printf("in mid\n");
			tmp = (*lst)->next;
			if ((*lst)->next->next)
				(*lst)->next = (*lst)->next->next;
			free(tmp->content);
			free(tmp);
			tmp = NULL;
		}
		*lst = (*lst)->next;
	}
	if (lst && *lst)
		free_part_end(ptr, lst);
	*lst = head;
}

void	print_lst(t_cal *lst)
{
	while (lst)
	{
		printf("content : %p\n", lst->content);
		lst = lst->next;
	}
}
