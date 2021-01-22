/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:05:37 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/22 12:10:27 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *curr;

	curr = *alst;
	if (alst)
	{
		if (*alst)
		{
			curr = ft_lstlast(*alst);
			curr->next = new;
		}
		else
			*alst = new;
	}
}
