/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:57:02 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/18 15:14:33 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (!alst || !new)
		return ;
	if (!(*alst))
		(*alst) = new;
	else
	{
		ptr = ft_lstlast(*alst);
		ptr->next = new;
	}
}
