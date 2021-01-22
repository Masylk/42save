/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:58:12 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/09 17:36:34 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	sizedest;
	size_t	sizesrc;
	size_t	j;

	i = 0;
	j = 0;
	sizedest = ft_strlen(dst);
	sizesrc = ft_strlen(src);
	if (size <= 0)
		return (sizesrc);
	if (size <= (unsigned int)sizedest)
		return (sizesrc + size);
	while (dst[i])
		i++;
	while (src[j] && i < size - 1)
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (sizedest + sizesrc);
}
