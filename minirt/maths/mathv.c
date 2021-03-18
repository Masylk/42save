/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:11:56 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/17 12:29:49 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		dot_product(t_vector i, t_vector j)
{
	double	a;
	double	b;
	double	c;

	a = i.x * j.x;
	b = i.y * j.y;
	c = i.z * j.z;
	return (a + b + c);
}

double		get_length(t_vector v)
{
	return (sqrt(dot_product(v, v)));
}

t_vector	normalize(t_vector v)
{
	double	invlen;
	double	len;

	len = get_length(v);
	if (len > 0)
	{
		invlen = 1 / len;
		v.x *= invlen;
		v.y *= invlen;
		v.z *= invlen;
	}
	return (v);
}
