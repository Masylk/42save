/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:23:16 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/27 14:54:41 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_double(int index, char **args)
{
	int		i;
	long int	nb;

	i = 0;
	nb = ft_atod(args[index]);
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	while (args[i])
	{
		if (i != index && nb == ft_atoi(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **args, int *n)
{
	int	i;

	i = 0;
	while (args[i])
		if (!(ft_strisdigit(args[i++])))
			return (0);
	i = 0;
	while (args[i])
	{
		if (!check_double(i++, args))
			return (0);
	}
	*n = i;
	return (1);
}
