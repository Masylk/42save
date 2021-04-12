/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:32:05 by mtogbe            #+#    #+#             */
/*   Updated: 2021/04/01 16:33:59 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	swap(t_stack *stack)
{
	int	s;

	if (stack && stack->next)
	{
		s = stack->n;
		stack->n = stack->next->n;
		stack->next->n = s;
		return (1);
	}
	return (0);
}

int	push(t_stack *stack_s, t_stack *stack_d)
{
	t_stack *tmp;
	
	tmp = stack_s;
	if (!tmp)
		return (0);
	stack_s = stack_s->next;
	tmp->next = stack_d;
	stack_d = tmp;
	return (1);
}

t_stack	*rotate(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*head;

	head = stack;
	if (!head)
		return (NULL);
	stack = stack->next;
	tmp = stack;
	if (!tmp)
		return (head);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	head->next = NULL;
	return (stack);
}

t_stack	*reverse_rotate(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	if (!tmp || !tmp->next)
		return (NULL);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = stack;
	stack = tmp->next;
	tmp->next = NULL;
	return (stack);
}
