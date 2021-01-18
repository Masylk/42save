/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:55:53 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/18 16:27:49 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	sizesrc;
	size_t	i;

	i = 0;
	sizesrc = ft_strlen(src);
	if (size == 0)
		return (sizesrc);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (sizesrc);
}

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

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s) + 1;
	p = malloc((size) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s, size);
	return (p);
}
