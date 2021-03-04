/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:02:49 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/03 15:45:26 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	check_plane(t_plane *plane, t_ray ray)
{
	double	denom;
	double	dist;

	denom = dot_product(ray.direction, plane->v);
	if (denom == 0)
		return (-1);
	dist = -dot_product(sub(ray.origin, plane->coor), plane->v) / denom;
	if (dist < 0)
		return (-1);
	return (dist);
}

int	check_planes(t_data *data, t_ray ray)
{
	t_plane	*tmp;
	double	t;

	tmp = data->planes;
	while (tmp)
	{
		t = check_plane(tmp, ray);
		if (t >= 0 && (data->elem.pos > t || data->elem.pos < 0))
		{
			data->elem.pos = t;
			data->elem.colour = tmp->colour;
			data->elem.normale = tmp->v;
			data->elem.point = add(ray.origin,
					mul_n(ray.direction, t));
		}
		tmp = tmp->next;
	}
	return (1);
}
