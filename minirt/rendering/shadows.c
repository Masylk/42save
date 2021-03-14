/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:48:15 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/14 15:45:17 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_rayshadow(t_data *data, t_ray *ray, t_light *light)
{
	ray->direction = normalize(sub(light->coor,
				data->elem.point));
	ray->origin = add(data->elem.point, mul_n(ray->direction, 0.1));
}

void	colour_pixel(unsigned char *dst, t_elem pixel, double lightvalue, t_vector lights)
{
	t_vector	pixel_colour;

	pixel_colour.x = min_d(255, max_d(pixel.colour.x, (lights.x + pixel.colour.x) / 2));
	pixel_colour.y = min_d(255, max_d(pixel.colour.y, (lights.y + pixel.colour.y) / 2));
	pixel_colour.z = min_d(255, max_d(pixel.colour.z,  (lights.z + pixel.colour.z) / 2));
	pixel_colour = mul_n(pixel_colour, lightvalue);
	dst[0] = min_d(255, max_d(0.0, pixel_colour.z) );//* (1.0 / 2.2));
	dst[1] = min_d(255, max_d(0.0, pixel_colour.y) );//* (1.0 / 2.2));
	dst[2] = min_d(255, max_d(0.0, pixel_colour.x) );//* (1.0 / 2.2));
}

int		compose_colour(t_data *data, t_light *light, double *lightvalue, t_elem pixel)
{
	t_ray		rayshadow;
	t_vector	dist;
	int			ret;

	set_rayshadow(data, &rayshadow, light);
	dist = normalize(sub(light->coor, pixel.point));
	ret = check_shapes(data, rayshadow);
	if (ret && (data->elem.pos * data->elem.pos) < dot_product(dist, dist))
		return (0);
	*lightvalue = min_d(1.3, (*lightvalue) +
			((light->ratio * 1.3 * dot_product(dist, pixel.normale))
				/ dot_product(dist, dist)));
	return (1);
}

void	add_ambient(t_data *data, unsigned char *dst)
{
	t_vector	colour;

	colour = mul_n(data->alight.colour, data->alight.ratio);
	dst[0] = min_d(255, (dst[0] + max_d(0, colour.x) * (1 / 2.2)));
	dst[1] = min_d(255, (dst[1] + max_d(0, colour.y) * (1 / 2.2)));
	dst[2] = min_d(255, (dst[2] + max_d(0, colour.z) * (1 / 2.2)));	
}

int	check_lights(t_data *data, unsigned char *dst)
{
	t_light		*light;
	double		lightvalue;
	t_vector	lightcolours;
	t_elem		pixel;

	light = data->lights;
	lightvalue = 0;
	lightcolours.x = 0.0;
	lightcolours.y = 0.0;
	lightcolours.z = 0.0;
	pixel = data->elem;
	while(light)
	{
		if (compose_colour(data, light, &lightvalue, pixel))
		{
			lightcolours.x = min_d(255, lightcolours.x + light->colour.x);
			lightcolours.x = min_d(255, lightcolours.y + light->colour.y);
			lightcolours.x = min_d(255, lightcolours.z + light->colour.z);
		}
		light = light->next;
	}
	colour_pixel(dst, pixel, lightvalue, lightcolours);
	add_ambient(data, dst);
	return (1);
}
