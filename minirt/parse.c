/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:12:51 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/15 15:32:58 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_pos(char *str, char **flags)
{
	int	i;
	int	j;

	i = 0;
	while (flags[i])
	{
		j = 0;
		while (str[j] && flags[i][j] && str[j] == flags[i][j])
			j++;
		if (!flags[i][j] && str[j] == ' ')
			return (i);
		i++;
	}
	return (-1);
}

int	get_flag(char *str)
{
	char	**flags;

	flags = malloc(sizeof(char *) * 10);
	if (!flags)
		return (-1);
	flags[0] = "R";
	flags[1] = "A";
	flags[2] = "c";
	flags[3] = "l";
	flags[4] = "pl";
	flags[5] = "sp";
	flags[6] = "sq";
	flags[7] = "cy";
	flags[8] = "tr";
	flags[9] = NULL;
	return (get_pos(str, flags));
}
