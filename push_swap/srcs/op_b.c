/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:26:16 by mtogbe            #+#    #+#             */
/*   Updated: 2021/04/01 16:36:43 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stacklist	double_rotate(t_stacklist l)
{
	t_stacklist res;
	res.stack_a = rotate(l.stack_a);
	res.stack_b = rotate(l.stack_b);
	res.tab = l.tab;	
	return (res);
}

t_stacklist	double_rev_rotate(t_stacklist l)
{
	t_stacklist res;
	res.stack_a = reverse_rotate(l.stack_a);
	res.stack_b = reverse_rotate(l.stack_b);
	res.tab = l.tab;
	return (res);
}

t_stacklist	*double_swap(t_stacklist *l)
{
	if (l->stack_a)
		swap(l->stack_a);
	if (l->stack_b)
		swap(l->stack_b);
	return (l);
}
