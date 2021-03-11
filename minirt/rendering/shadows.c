/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:48:15 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/11 15:27:13 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_rayshadow(t_data *data, t_ray *ray)
{
	ray->direction = normalize(sub(data->lights->coor,
				data->elem.point));
	ray->origin = add(data->elem.point, mul_n(ray->direction, 0.01));
}

void	colour_pixel(char *dst, t_elem pixel, t_light *light)
{
	t_vector	pixel_colour;
	t_vector	dist;
	double		lightvalue;

	dist = normalize(sub(light->coor, pixel.point));
	lightvalue = (light->ratio * 1.3 * max_d(0.0,
				dot_product(dist,
				normalize(pixel.normale))))
	/ (dot_product(dist, dist) * (1 / 2.2));
	pixel_colour = mul_n(add(pixel.colour, light->colour), lightvalue);
	dst[0] = min_d(255, dst[0] + max_d(0, pixel_colour.z) * (1 / 2.2));
	dst[1] = min_d(255, dst[1] + max_d(0, pixel_colour.y) * (1 / 2.2));
	dst[2] = min_d(255, dst[2] + max_d(0, pixel_colour.x) * (1 / 2.2));
}

int		compose_colour(t_data *data, char *dst, t_light *light)
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
	colour_pixel(dst, pixel, light);
	return (1);
}

void	add_ambient(t_data *data, char *dst)
{
	t_vector	colour;

	colour = mul_n(data->alight.colour, data->alight.ratio * 1.3);
	dst[0] = min_d(255, dst[0] + max_d(0, colour.x) * (1 / 2.2));
	dst[1] = min_d(255, dst[1] + max_d(0, colour.y) * (1 / 2.2));
	dst[2] = min_d(255, dst[2] + max_d(0, colour.z) * (1 / 2.2));	
}

int		check_lights(t_data *data, t_ray ray, char *dst)
{
	(void)ray;
	t_light	*light;

	light = data->lights;
	add_ambient(data, dst);
	compose_colour(data, dst, light);
	while(!light)
	{
		compose_colour(data, dst, light);
		light = light->next;
	}
	return (1);
}

