/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:44:34 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/09 17:37:08 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = ft_calloc(ft_strlen(s), sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s, ft_strlen(s) + 1);
	while (result[i])
	{
		result[i] = (*f)(i, result[i]);
		i++;
	}
	return (result);
}
