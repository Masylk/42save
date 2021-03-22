/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:03:02 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/22 17:13:45 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_spheres(t_data *data, t_ray ray)
{
	t_sphere	*tmp;
	double		t;

	t = -1;
	tmp = data->spheres;
	while (tmp)
	{
		t = check_sphere(tmp, ray);
		if (t > 0.0 && (t < data->elem.pos))
		{
			data->elem.pos = t;
			data->elem.colour = tmp->colour;
			data->elem.point = add(ray.origin,
					mul_n(ray.direction, t));
			data->elem.normale = normalize(sub(data->elem.point,
				tmp->coor));
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
	double		q;

	k.d = sub(ray.origin, sphere->coor);
	r = sphere->width * 0.5;
	k.a = dot_product(ray.direction, ray.direction);
	k.b = 2.0 * dot_product(ray.direction, k.d);
	k.c = dot_product(k.d, k.d) - r * r;
	delta = k.b * k.b - 4.0 * k.a * k.c;
	if (delta < 0.0)
		return (-1);
	delta = sqrt(delta);
	if (k.b > 0)
		q = -0.5 * (k.b + delta);
	else
		q = -0.5 * (k.b - delta);
	k.t = q / k.a;
	k.t_one = k.c / q;
	if (k.t < 0.0)
		return (-1);
	if (k.t > k.t_one && k.t_one > 0.0)
		return (k.t_one);
	return (k.t);
}
