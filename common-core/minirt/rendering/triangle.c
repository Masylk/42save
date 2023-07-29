/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:07:08 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/22 17:20:14 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_inside(t_triangle *triangle, t_vector normale, t_vector point)
{
	t_vector	edge;
	t_vector	pos;

	edge = sub(triangle->coor_b, triangle->coor_a);
	pos = sub(point, triangle->coor_a);
	if (dot_product(normale, cross_product(edge, pos)) < 0.0)
		return (0);
	edge = sub(triangle->coor_c, triangle->coor_b);
	pos = sub(point, triangle->coor_b);
	if (dot_product(normale, cross_product(edge, pos)) < 0.0)
		return (0);
	edge = sub(triangle->coor_a, triangle->coor_c);
	pos = sub(point, triangle->coor_c);
	if (dot_product(normale, cross_product(edge, pos)) < 0.0)
		return (0);
	return (1);
}

int	is_triangle(t_tools k)
{
	double	detm;
	double	detb;
	double	detg;

	k.ma = dot_product(k.u, k.u);
	k.mb = dot_product(k.u, k.v);
	k.mc = dot_product(k.v, k.v);
	detm = k.ma * k.mc - k.mb * k.mb;
	k.ba = dot_product(k.w, k.u);
	k.bb = dot_product(k.w, k.v);
	detb = k.ba * k.mc - k.bb * k.mb;
	k.b = detb / detm;
	detg = k.ma * k.bb - k.mb * k.ba;
	k.c = detg / detm;
	k.a = 1 - k.b - k.c;
	if (k.a < 0 || k.a > 1 || k.b < 0 || k.b > 1
			|| k.c < 0 || k.c > 1)
		return (0);
	return (1);
}

int	check_triangle(t_triangle *triangle, t_ray ray)
{
	t_vector	normale;
	t_vector	point;
	double		a;
	double		t;
	t_tools		k;

	normale = triangle->normale;
	a = dot_product(ray.direction, normale);
	if (a == 0.0)
		return (-1);
	t = (dot_product(sub(triangle->coor_c, ray.origin), normale)) / a;
	if (t < 0.0)
		return (-1);
	point = add(ray.origin, mul_n(ray.direction, t));
	k.u = sub(triangle->coor_b, triangle->coor_a);
	k.v = sub(triangle->coor_c, triangle->coor_a);
	k.w = sub(point, triangle->coor_a);
	if (is_triangle(k))
		return (t);
	return (-1);
}

int	check_triangles(t_data *data, t_ray ray)
{
	t_triangle	*tmp;
	double		t;

	tmp = data->triangles;
	while (tmp)
	{
		t = check_triangle(tmp, ray);
		if (t < 0.0)
		{
			tmp->normale = mul_n(tmp->normale, -1);
			t = check_triangle(tmp, ray);
			if (t < 0.0)
				tmp->normale = mul_n(tmp->normale, -1);
		}
		if (t > 0.0 && (t < data->elem.pos))
		{
			data->elem.pos = t;
			data->elem.colour = tmp->colour;
			data->elem.normale = tmp->normale;
			data->elem.point = add(ray.origin,
					mul_n(ray.direction, t));
		}
		tmp = tmp->next;
	}
	return (1);
}
