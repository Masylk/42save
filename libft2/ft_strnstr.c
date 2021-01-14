/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:00:02 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/09 17:37:22 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (!s2[i])
		return ((char *)s1);
	while (i < len && s1[i])
	{
		j = 0;
		while (s2[j] && s1[i] && s2[j] == s1[i + j] && i + j < len)
			j++;
		if (!s2[j])
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
