/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:04:46 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/20 17:10:41 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
