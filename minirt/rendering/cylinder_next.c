/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:13:47 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/12 13:35:24 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	copy_cyl(t_cyl *cyl, t_cyl *tmp)
{
	tmp->coor = cyl->coor;
	tmp->height = cyl->height;
	tmp->width = cyl->width;
	tmp->v = cyl->v;
	tmp->colour = cyl->colour;
}

double	check_caps(t_ray ray, t_cyl *cyl, t_data *data, double res)
{
	double		t;
	double		t_one;
	t_cyl		tmp;
	t_vector	bottom;
	t_vector	top;

	copy_cyl(cyl, &tmp);
	bottom = add(cyl->coor, mul_n(cyl->v, cyl->height * 0.5));
	tmp.coor = bottom;
	t = check_circle(ray, &tmp);
	top = sub(cyl->coor, mul_n(cyl->v, cyl->height * 0.5));
	tmp.coor = top;
	t_one = check_circle(ray, &tmp);
	if ((t > t_one || t < 0.0) && t_one > 0.0 && res > t_one)
	{
		data->elem.normale = mul_n(cyl->v, -1);
		return (t_one);
	}
	else if ((res > t || res < 0.0) && t > 0.0)
	{
		data->elem.normale = cyl->v;
		return (t);
	}
	return (res);
}
