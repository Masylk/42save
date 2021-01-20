/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:31:16 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/20 17:10:17 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	cc;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	cs = (unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (cs[i] == cc)
			return (cs + i);
		i++;
	}
	return (NULL);
}
