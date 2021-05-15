/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:30:48 by mtogbe            #+#    #+#             */
/*   Updated: 2021/05/15 18:18:06 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "calloc.h"

t_cal	*my_calloc(size_t nmemb, size_t size, void **ptr)
{
	static t_cal	*list;
	t_cal			*new;

	if (!ptr)
		return (list);
	if (!nmemb || !size)
	{
		*ptr = NULL;
		return (list);
	}
	*ptr = malloc(nmemb * size);
	if (!(*ptr))
		return (list);
	new = malloc(sizeof(t_cal));
	new->content = *ptr;
	new->next = list;
	list = new;
	return (list);
}

void	free_all(t_cal *lst)
{
	t_cal	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->content);
		free(tmp);
		printf("free\n");
	}
}

void	free_part_end(void *ptr, t_cal *list)
{
	
}

void	free_part(void *ptr)
{
	t_cal	*list;
	t_cal	*tmp;

	list = my_calloc(0, 0, NULL);
	if (list && list->content == ptr)
	{
		tmp = list;
		if (list->next)
			list = list->next;
		free(tmp->content);
		free(tmp);
		return ;
	}
	while (list && list->next)
	{
		if (list->next->content == ptr)
		{
			tmp = list->next;
			if (list->next->next)
				list->next = list->next->next;
			free(tmp->content);
			free(tmp);
			tmp = NULL;
		}
		list = list->next;
	}
	if (list)
		free_part_end(ptr, list);
}

int	main()
{
	char	*str;
	t_cal	*lst;

	lst = my_calloc(8, sizeof(char), (void *)&str);
	lst = my_calloc(8, sizeof(char), (void *)&str);
	lst = my_calloc(8, sizeof(char), (void *)&str);
	lst = my_calloc(8, sizeof(char), (void *)&str);
	lst = my_calloc(8, sizeof(char), (void *)&str);
	while (lst)
	{
		printf("alloc\n");
		lst = lst->next;
	}
	free_all(my_calloc(0,0, NULL));
}
