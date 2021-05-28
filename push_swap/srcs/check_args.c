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

int	check_args(char **args, int *n)
{
	int	i;

	i = 0;
	while (args[i])
		if (!(ft_strisdigit(args[i++])))
			return (0);
	*n = i + 1;
	return (1);
}