/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:41:34 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/03 15:25:01 by mtogbe           ###   ########.fr       */
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

static void		getnb(char **result, char *base, long long n, int pos)
{
	if (n < (long long)ft_strlen(base))
		(*result)[pos] = base[n % ft_strlen(base)];
	else
	{
		getnb(result, base, n / ft_strlen(base), pos - 1);
		(*result)[pos] = base[n % ft_strlen(base)];
	}
}

char			*ft_ultoa_base(unsigned long n, char *base)
{
	char		*result;
	int			size;
	long long	nb;
	int			baselen;

	baselen = ft_strlen(base);
	nb = n;
	size = get_nb_size(baselen, nb);
	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[size] = '\0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	getnb(&result, base, nb, size - 1);
	return (result);
}
