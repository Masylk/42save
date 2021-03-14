/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:05:16 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/14 14:30:34 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_square(t_square *square, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	t_vector	dist;
	double		area;

	a = dot_product(sub(ray.origin, square->coor), square->v);
	b = dot_product(ray.direction, square->v);
	if (b == 0.0)
		return (-1);
	c = -(a / b);
	area = square->width * 0.5;
	dist = sub(add(mul_n(ray.direction, c), ray.origin), square->coor);
	if (fabs(dist.x) > area || fabs(dist.y) > area || fabs(dist.z) > area)
		return (-1);
	if (c >= 0.0)
		return (c);
	return (-1);
}

int	check_squares(t_data *data, t_ray ray)
{
	t_square	*tmp;
	double		t;

	tmp = data->squares;
	while (tmp)
	{
		t = check_square(tmp, ray);
		if (t > 0.0 && (data->elem.pos > t || data->elem.pos < 0.0))
		{
			data->elem.pos = t;
			data->elem.colour = tmp->colour;
			data->elem.normale = normalize(tmp->v);
			data->elem.point = add(ray.origin,
					mul_n(ray.direction, t));
		}
		tmp = tmp->next;
	}
	return (1);
}
