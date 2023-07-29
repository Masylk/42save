/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:10:08 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 02:10:45 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pb(t_stack **a, t_stack **b)
{
	if (!push(a, b))
		return (0);
	ft_printf("pb\n");
	return (1);
}

int	sb(t_stack *b)
{
	if (!swap(b))
		return (0);
	ft_printf("sb\n");
	return (1);
}

t_stack	*rb(t_stack *b)
{
	b = rotate(b);
	if (!b)
		return (b);
	ft_printf("rb\n");
	return (b);
}

t_stack	*rrb(t_stack *b)
{
	b = reverse_rotate(b);
	if (!b)
		return (b);
	ft_printf("rrb\n");
	return (b);
}

//finir correctement avec stacklist
t_stack	*rrr(t_stack *a, t_stack *b)
{
	b = rotate(b);
	if (!b)
		return (b);
	a = rotate(a);
	if (!a)
		return (a);
	return (b);
}
