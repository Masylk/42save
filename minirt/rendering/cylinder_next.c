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

double	check_caps(t_ray ray, t_cyl *cyl)
{
	double	t;
	double	t_one;
	t_cyl	*tmp;

	tmp = cyl;
	//t = check_circle(ray, cyl);
	//return (t);
	tmp->coor = add(cyl->coor, mul_n(cyl->v, cyl->height * 0.5));
	t = check_circle(ray, tmp);
	tmp->coor = sub(cyl->coor, mul_n(cyl->v, cyl->height * 0.5));
	t_one = check_circle(ray, tmp);
	if (t > t_one && t_one > 0)
		return (t_one);
	return (t);
}
