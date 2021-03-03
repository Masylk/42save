/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:13:47 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/03 15:27:25 by mtogbe           ###   ########.fr       */
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

double	check_caps(t_ray ray, t_cyl *cyl)
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
	if (t < t_one && t_one > 0)
	{
		cyl->coor = top;
		return (t_one);
	}
	cyl->coor = bottom;
	return (t);
}
