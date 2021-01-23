/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:01:00 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/22 12:12:52 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*list;

	if (!lst || !f || !del)
		return (NULL);
	result = ft_lstnew((*f)(lst->content));
	if (!result)
	{
		ft_lstclear(&lst, (*del));
		return (NULL);
	}
	list = result;
	lst = lst->next;
	while (lst)
	{
		result = ft_lstnew((*f)(lst->content));
		if (!result)
		{
			ft_lstclear(&lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&list, result);
		lst = lst->next;
	}
	return (list);
}
