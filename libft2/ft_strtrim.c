/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:08:17 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/09 17:37:38 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		len;
	char	*result;
	int		start;

	end = 0;
	result = ft_calloc(1, sizeof(char));
	len = ft_strlen(s1) - 1;
	start = get_start(s1, set);
	if (start == len + 1)
		return (result);
	while (len > 0 && ft_strchr(set, s1[len--]))
		end += 1;
	result = ft_calloc(ft_strlen(s1) - start - end, sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, (char *)s1 + start,
			ft_strlen((char *)s1 + start) - end + 1);
	return (result);
}
