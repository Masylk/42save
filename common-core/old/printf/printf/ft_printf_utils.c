/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:43:41 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/04 16:49:37 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getpos(char c, char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_nblen(int nb)
{
	int	i;

	i = 1;
	while (nb / 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	set_flag(int *flag)
{
	*flag = 1;
	return (1);
}

int	set_size(int *width, char *str)
{
	*width = ft_atoi(str);
	return (ft_nblen(*width));
}
