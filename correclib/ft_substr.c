/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:04:40 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/22 12:10:17 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		res[i] = '\0';
		return (res);
	}
	while (i < len && s[start])
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
