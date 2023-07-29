/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:06:04 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/20 17:12:49 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;

	if (!s)
		return (NULL);
	p = ft_calloc(len, sizeof(char));
	if (!p)
		return (NULL);
	s = s + start;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ft_strlcpy(p, s, len + 1);
	return (p);
}
