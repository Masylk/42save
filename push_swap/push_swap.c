/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:43:28 by mtogbe            #+#    #+#             */
/*   Updated: 2021/04/01 16:37:19 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*arr_to_stack(char **arr)
{
	t_stack	*stack;
	int		i;
	t_stack	*tmp;
	t_stack *head;

	i = 0;
	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->n = ft_atoi(arr[i++]);
	tmp->next = NULL;
	stack = tmp;
	head = stack;
	while (arr[i])
	{
		tmp = malloc(sizeof(t_stack));
		if (!tmp)
			return (NULL);
		tmp->n = ft_atoi(arr[i++]);
		tmp->next = NULL;
		stack->next = tmp;
		stack = stack->next;
	}
	return (head);
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

int		main(int ac, char **av)
{
	int			size_stack;
	t_stacklist	list;

	if (ac < 2)
		return (ft_printf("Error\n"));
	if (!(check_args(av + 1, &size_stack)))
		return (ft_printf("Error\n"));
	list.stack_a = arr_to_stack(av + 1);
	if (!list.stack_a)
		return (0);
	double_swap(&list);
	print_stack((&list)->stack_a);
}