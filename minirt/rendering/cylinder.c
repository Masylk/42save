/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:10:49 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/22 17:14:14 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	is_inplanes(double t_one, double t_two, t_ray ray, t_cyl *cyl)
{
	t_vector	q;
	t_vector	p_one;
	t_vector	p_two;
	double		t;

	t = -1;
	p_one = sub(cyl->coor, mul_n(cyl->v, cyl->height * 0.5));
	p_two = add(cyl->coor, mul_n(cyl->v, cyl->height * 0.5));
	if (t_one > 0.0)
	{
		q = add(ray.origin, mul_n(ray.direction, t_one));
		if (dot_product(cyl->v, sub(q, p_one)) > 0.0
				&& dot_product(cyl->v, sub(q, p_two)) < 0.0)
			t = t_one;
	}
	if (t_two > 0.0)
	{
		q = add(ray.origin, mul_n(ray.direction, t_two));
		if (dot_product(cyl->v, sub(q, p_one)) < 0.0
				|| dot_product(cyl->v, sub(q, p_two)) > 0.0)
			return (t);
		if (t > t_two || t < 0.0)
			t = t_two;
	}
	return (t);
}

double	check_circle(t_ray ray, t_cyl *cyl)
{
	t_vector	point;
	double		a;
	double		b;
	double		c;

	a = dot_product(sub(ray.origin, cyl->coor), cyl->v);
	b = dot_product(ray.direction, cyl->v);
	if (b == 0.0 || (a > 0.0 && b > 0.0) || (a < 0.0 && b < 0.0))
		return (-1);
	c = -(a / b);
	point = sub(add(ray.origin, mul_n(ray.direction, c)), cyl->coor);
	if ((int)dot_product(cyl->v, point) != 0.0)
		return (-1);
	if (dot_product(point, point) >=
			cyl->width * 0.5 * cyl->width * 0.5)
		return (-1);
	else
		return (c);
}

double	check_disc(double d, t_ray ray, t_cyl *cyl, t_tools ts)
{
	t_tools		k;
	double		sq;

	sq = sqrt(d);
	ts.a = 2.0 * ts.a;
	k.t_one = (-ts.b + sq) / ts.a;
	k.t_two = (-ts.b - sq) / ts.a;
	if (k.t_one <= 0.0 && k.t_two <= 0.0)
		return (-1);
	k.t_one = is_inplanes(k.t_one, k.t_two, ray, cyl);
	if (k.t_one < 0.0)
		return (-1);
	return (k.t_one);
}

int		check_cylinder(t_cyl *cyl, t_ray ray, t_data *data)
{
	t_tools		k;
	double		res;

	k.v = sub(ray.direction,
			mul_n(cyl->v, dot_product(ray.direction, cyl->v)));
	k.d = sub(ray.origin, cyl->coor);
	k.a = dot_product(k.v, k.v);
	k.b = 2.0 * dot_product(k.v,
			sub(k.d, mul_n(cyl->v, dot_product(k.d, cyl->v))));
	k.v = sub(k.d, mul_n(cyl->v, dot_product(k.d, cyl->v)));
	k.c = dot_product(k.v, k.v) - ((cyl->width * 0.5) * (cyl->width * 0.5));
	k.c = (k.b * k.b) - (4 * k.a * k.c);
	res = -1;
	if (k.c >= 0.0)
		res = check_disc(k.c, ray, cyl, k);
	if (res > 0.0)
	{
		k.d = add(ray.origin, mul_n(ray.direction, res));
		k.n = dot_product(sub(k.d, cyl->coor), cyl->v);
		data->elem.normale = normalize(sub(k.d,
					add(cyl->coor, mul_n(cyl->v, k.n))));
	}
	res = check_caps(ray, cyl, data, res);
	return (res);
}

int		check_cylinders(t_data *data, t_ray ray)
{
	t_cyl	*tmp;
	double	t;

	tmp = data->cylindres;
	while (tmp)
	{
		t = check_cylinder(tmp, ray, data);
		if (t > 0.0 && (t < data->elem.pos))
		{
			data->elem.pos = t;
			data->elem.colour = tmp->colour;
			data->elem.point = add(ray.origin,
					mul_n(ray.direction, t));
		}
		tmp = tmp->next;
	}
	return (1);
}
