/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:05:03 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/22 12:10:24 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_taille_word(const char *s, char c)
{
	int len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

int		ft_sep(char curr, char c)
{
	return (curr == c);
}

int		ft_nbwords(const char *s, char c)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (*s)
	{
		if (ft_sep(*s, c))
			s++;
		else
		{
			while (*s && !ft_sep(*s, c))
				s++;
			len++;
		}
	}
	return (len);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i;
	int		nb_words;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	nb_words = ft_nbwords(s, c);
	res = malloc(sizeof(char *) * (nb_words + 1));
	if (!res)
		return (NULL);
	while (nb_words > 0)
	{
		while (*s && *s == c)
			s++;
		len = ft_taille_word(s, c);
		res[i] = ft_substr(s, 0, len);
		s = s + len;
		i++;
		nb_words--;
	}
	res[i] = NULL;
	return (res);
}
