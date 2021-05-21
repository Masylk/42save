/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:30:48 by mtogbe            #+#    #+#             */
/*   Updated: 2021/05/20 18:09:57 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calloc.h"

t_cal	**my_calloc(size_t nmemb, size_t size, void **ptr)
{
	static t_cal	*list = NULL;
	t_cal			*new;

	if (!ptr)
		return (&list);
	if (!nmemb || !size)
	{
		*ptr = NULL;
		return (&list);
	}
	*ptr = ft_calloc(nmemb, size);
	if (!(*ptr))
		return (NULL);
	new = malloc(sizeof(t_cal));
	new->content = *ptr;
	new->next = list;
	list = new;
	return (&list);
}

void	free_all(t_cal **lst)
{
	t_cal	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->content);
		free(tmp);
	}
}

/*int	main()
{
	char	*str;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	t_cal	**lst;
	t_cal	*head;
	
	lst = my_calloc(8, sizeof(char), (void *)&str);
	lst = my_calloc(8, sizeof(char), (void *)&str1);
	lst = my_calloc(8, sizeof(char), (void *)&str2);
	lst = my_calloc(8, sizeof(char), (void *)&str3);
	lst = my_calloc(8, sizeof(char), (void *)&str4);
	*lst = free_part((void *)str2, *lst);
	*lst = free_part((void *)str1, *lst);
	*lst = free_part((void *)str, *my_calloc(0,0,NULL));
	*lst = free_part((void *)str3, *lst);
	*lst = free_part((void *)str4, *lst);
	free_all(*my_calloc(0,0,NULL));
	print_lst(*lst);	
}*/
