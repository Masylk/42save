/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:23:16 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/25 16:32:37 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_args(char **args, int *n)
{
	int	i;

	i = 0;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (!(ft_strisdigit(args[i++])))
			return (0);
	}
	*n = i + 1;
	return (1);
}
