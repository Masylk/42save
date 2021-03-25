/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:41:34 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/14 15:19:49 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_nb_size(int base, long long n)
{
	int	size;

	if (n < 0)
	{
		n = -n;
		size = 2;
	}
	else
		size = 1;
	while (n / base > 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

static void		getnb(char **result, int base, long long n, int pos)
{
	if (n < base)
		(*result)[pos] = n % base + '0';
	else
	{
		getnb(result, base, n / base, pos - 1);
		(*result)[pos] = n % base + '0';
	}
}

char			*ft_itoa(int n)
{
	char		*result;
	int			size;
	long long	nb;

	nb = n;
	size = get_nb_size(10, nb);
	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[size] = '\0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	getnb(&result, 10, nb, size - 1);
	return (result);
}
