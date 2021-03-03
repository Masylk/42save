/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:03:02 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/03 14:28:02 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_spheres(t_data *data, t_ray ray)
{
	t_sphere	*tmp;
	double		t;

	tmp = data->spheres;
	while (tmp)
	{
		t = check_sphere(tmp, ray);
		if (t > 0 && (data->elem.pos > t || data->elem.pos < 0))	
		{
			data->elem.pos = t;
			data->elem.colour = tmp->colour;
			data->elem.coor = tmp->coor;
		}
		tmp = tmp->next;
	}
	return (t);
}

double	check_sphere(t_sphere *sphere, t_ray ray)
{
	t_tools		k;
	double		r;
	double		delta;

	k.d = sub(ray.origin, sphere->coor);
	r = sphere->width * 0.5;
	k.a = dot_product(ray.direction, ray.direction);
	k.b = 2 * dot_product(ray.direction, k.d);
	k.c = dot_product(k.d, k.d) - r * r;
	delta = k.b * k.b - 4 * k.a * k.c;
	if (delta < 0)
		return (-1);
	delta = sqrt(delta);
	k.a = 2 * k.a;
	k.t = (-k.b + delta) / k.a;
	if (k.t > 0)
		return (k.t);
	return (-1);
}
