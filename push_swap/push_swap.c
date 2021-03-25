/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:43:28 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/25 16:59:31 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*arr_to_stack(char **arr, int size)
{
	int	*stack;
	int	i;

	i = 0;
	stack = malloc(size);
	if (!stack)
		return (NULL);
	while (arr[i])
	{
		stack[i] = ft_atoi(arr[i]);
		i++;
	}
	return (stack);
}

int	main(int ac, char **av)
{
	int	size_stack;
	int	*stack;

	if (ac < 2)
		return (ft_printf("Error\n"));
	if (!(check_args(av + 1, &size_stack)))
		return (ft_printf("Error\n"));
	stack = arr_to_stack(av + 1, size_stack);
	if (!stack)
		return (0);
}
