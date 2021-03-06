/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:02:58 by flohrel           #+#    #+#             */
/*   Updated: 2021/05/29 09:19:07 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*lst_alloc(size_t nmemb, size_t size, t_vars *vars)
{
	void	*ptr;

	ptr = garbage_collector(nmemb, size, &vars->ptr_list);
	if (ptr == NULL)
		clean_exit(vars, errno);
	return (ptr);
}
