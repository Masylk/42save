/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:16:35 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/17 15:20:57 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	freetab(char **tab, int value)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
	return (value);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	str_digit(char *str)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (!(ft_isdigit(str[i])) || str[i++] != '-')
		return (0);
	while (str[i] && (ft_isdigit(str[i]) || !point))
	{
		if (str[i] == '.' && !point)
			point = 1;
		else if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	if (str[i] && point)
		return (0);
	else if (!str[i] && !(ft_isdigit(str[i - 1])))
		return (0);
	return (1);
}

int	get_double(double *n, char *str)
{
	if (str_digit(str))
		*n = ft_atod(str);
	else
		return (0);
	return (1);
}

int	get_point(char *str, t_vector *v)
{
	char	**tab;

	tab = ft_split(str, ',');
	if (!tab)
		return (0);
	if (ft_tablen(tab) != 3)
		return (freetab(tab, 0));
	if (!(get_double(&(v->x), tab[0]))
			|| !(get_double(&(v->y), tab[1]))
			|| !(get_double(&(v->z), tab[2])))
		return (freetab(tab, 0));
	return (freetab(tab, 1));
}
