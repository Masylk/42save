/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:28:38 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/09 17:38:37 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	unsigned char	cc;
	size_t			i;

	i = 0;
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	cc = (unsigned char)c;
	while (i < n)
	{
		cdest[i] = csrc[i];
		if (cdest[i] == cc)
			return (cdest + i + 1);
		i++;
	}
	return (NULL);
}
