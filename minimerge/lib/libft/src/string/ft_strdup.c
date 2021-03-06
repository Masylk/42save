/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:13:14 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/16 15:58:45 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	char	*dup;
	size_t	len;

	len = ft_strlen(s);
	my_calloc(len + 1, sizeof(*dup), (void *)&dup);
	if (!dup)
		return (dup);
	d = dup;
	while (len--)
		*d++ = *s++;
	*d = '\0';
	return (dup);
}
