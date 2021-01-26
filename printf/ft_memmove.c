/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:49:08 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/20 17:10:20 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;
	size_t				i;
	int					idx;

	if (!dest || !src)
		return (dest);
	cdest = (unsigned char *)dest;
	csrc = (const unsigned char *)src;
	i = 0;
	idx = 1;
	if (csrc < cdest)
	{
		i = n - 1;
		idx = -1;
	}
	while (n--)
	{
		cdest[i] = csrc[i];
		i += idx;
	}
	return (dest);
}
