/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:02:56 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 02:20:59 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	convert_nb(const char *nb, double *result, double *div)
{
	static int	i = 0;
	static int	isdec = 0;

	while (nb[i] && (ft_isdigit(nb[i])))
	{
		*result = *result * 10 + nb[i++] - '0';
		if (isdec)
			*div *= 10;
	}
	if (nb[i] == '.')
	{
		isdec = 1;
		i++;
		return (1);
	}
	i = 0;
	isdec = 0;
	return (0);
}

double	ft_atod(const char *nptr)
{
	double	sign;
	double	result;
	double	div;
	int		isdecimal;

	sign = 1;
	div = 1;
	result = 0;
	isdecimal = 0;
	if (!nptr)
		return (0);
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while ((convert_nb(nptr, &result, &div) || isdecimal))
	{
	}
	return ((result / div) * sign);
}
