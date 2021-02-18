/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:21:11 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/18 17:11:02 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	printlights(t_light *list)
{
	t_light	light;

	while (list)
	{
		light.coor = list->coor;
		light.colour = list->colour;
		light.ratio = list->ratio;
		printlight(light);
		list = list->next;
	}
}
