/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:57:48 by mtogbe            #+#    #+#             */
/*   Updated: 2021/05/19 16:49:00 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calloc.h"


t_cal	*free_part_mid(t_cal *lst, void *ptr)
{
	t_cal	*stack;
	t_cal	*head;

	head = lst;
	while (lst && lst->next && lst->next->next)
	{
		if (lst->next->content == ptr)
		{
			stack = lst->next;
			lst->next = lst->next->next;
			free(stack->content);
			free(stack);
		}
		lst = lst->next;
	}
	return (head);
}


t_cal	*free_part(void *ptr, t_cal *lst)
{
	t_cal	*tmp;
	t_cal	*stack;
	t_cal	*head;

	head = lst;
	if (lst->content == ptr)
	{
		stack = lst;
		lst = lst->next;
		free(stack->content);
		free(stack);
		return (lst);
	}
	tmp = free_part_mid(lst, ptr);
	head = tmp;
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	if (tmp->next->content == ptr)
	{
		free(tmp->next->content);
		free(tmp->next);
		tmp->next = NULL;
	}
	return (head);
}

void	print_lst(t_cal *lst)
{
	while (lst)
	{
		printf("content : %p\n", lst->content);
		lst = lst->next;
	}
	printf("------------\n");
}
