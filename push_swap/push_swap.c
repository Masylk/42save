/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:43:28 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 02:12:56 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*arr_to_stack(char **arr)
{
	t_stack	*stack;
	int		i;
	t_stack	*tmp;
	t_stack	*head;

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
		ft_printf("%d : ", tmp->n);
		ft_printf("%d\n", tmp->pos);
		tmp = tmp->next;
	}
}

void	print_tab(int *tab, t_stack *stack)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(stack);
	while (i < size)
	{
		ft_printf("%d \n", tab[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	int			size_stack;
	t_stacklist	list;

	if (ac < 2)
		return (ft_printf("Error\n"));
	if (ac == 2 && !ft_strisdigit(av[1]))
	{
		av = ft_split(av[1], ' ');
		if (!check_args(av, &size_stack))
			return (ft_printf("Error\n"));
	}
	else if (!(check_args(av + 1, &size_stack)))
		return (ft_printf("Error\n"));
	else
		av = av + 1;
	if (init_stacks(&list, av) < 0)
		return (ft_printf("Error\n"));
	if (!small_sorts(&list, size_stack))
		rd_sort_stack(&list, size_stack);
	free_stlist(&list);
}
