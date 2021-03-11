/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:48:15 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/11 13:57:20 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_rayshadow(t_data *data, t_ray *ray)
{
	ray->direction = normalize(sub(data->lights->coor,
				data->elem.point));
	ray->origin = add(data->elem.point, mul_n(ray->direction, 0.01));
}

void	colour_pixel(t_data *data, char *dst, t_elem pixel)
{
	t_vector	pixel_colour;
	t_vector	dist;
	double		lightvalue;

	dist = normalize(sub(data->lights->coor, pixel.point));
	lightvalue = (data->lights->ratio * 1.3 * max_d(0.0,
				dot_product(dist,
				normalize(pixel.normale))))
	/ (dot_product(dist, dist) * (1 / 2.2));
	pixel_colour = mul_n(pixel.colour, lightvalue);
	dst[0] += min_d(255, max_d(0, pixel_colour.z)) * (1 / 2.2);
	dst[1] += min_d(255, max_d(0, pixel_colour.y) * (1 / 2.2));
	dst[2] += min_d(255, max_d(0, pixel_colour.x) * (1 / 2.2));
}

int		compose_colour(t_data *data, char *dst)
{
	t_elem		pixel;
	t_ray		rayshadow;
	t_vector	dist;
	int			ret;

	dist = data->elem.point;
	pixel = data->elem;
	set_rayshadow(data, &rayshadow);
	ret = check_shapes(data, rayshadow);
	if (ret && (data->elem.pos * data->elem.pos) < dot_product(dist, dist))
		return (0);
	colour_pixel(data, dst, pixel);
	return (1);
}

int		check_lights(t_data *data, t_ray ray, char *dst)
{
	(void)ray;
	compose_colour(data, dst);
	return (1);
}

