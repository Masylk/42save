/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:48:15 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/17 16:49:56 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_rayshadow(t_elem pixel, t_ray *ray, t_light *light)
{
	ray->direction = normalize(sub(light->coor,
				pixel.point));
	ray->origin = add(pixel.point, mul_n(ray->direction, 2.2));
}

void	colour_pixel(unsigned char *d, t_elem pixel, double l, t_vector lights)
{
	t_vector	pixel_colour;

	pixel_colour.x = min_d(255, min_d(pixel.colour.x, lights.x));
	pixel_colour.y = min_d(255, min_d(pixel.colour.y, lights.y));
	pixel_colour.z = min_d(255, min_d(pixel.colour.z, lights.z));
	pixel_colour = mul_n(pixel_colour, l);
	d[0] = min_d(255, max_d(0.0, pixel_colour.z));
	d[1] = min_d(255, max_d(0.0, pixel_colour.y));
	d[2] = min_d(255, max_d(0.0, pixel_colour.x));
}

int		compose_colour(t_data *data, t_light *light, double *l, t_elem p)
{
	t_ray		rayshadow;
	t_vector	dist;
	int			ret;
	double		i;

	set_rayshadow(p, &rayshadow, light);
	dist = sub(light->coor, p.point);
	ret = check_shapes(data, rayshadow);
	if (ret && (data->elem.pos * data->elem.pos) < dot_product(dist, dist))
		return (0);
	i = min_d(1, (light->ratio * 100.3 * dot_product(dist, p.normale))
				/ dot_product(dist, dist));
	*l = min_d(1, *l + i);
	return (i);
}

t_vector	add_ambient(t_data *data, double *l, t_vector lcolours)
{
	t_vector	colour;

	*l = min_d(1, *l + data->alight.ratio);
	colour = mul_n(data->alight.colour, data->alight.ratio);
	lcolours.x = min_d(255, (lcolours.x + max_d(0, colour.x)));
	lcolours.y = min_d(255, (lcolours.y + max_d(0, colour.y)));
	lcolours.z = min_d(255, (lcolours.z + max_d(0, colour.z)));
	return (lcolours);
}

int		check_lights(t_data *data, unsigned char *dst)
{
	t_light		*light;
	double		lightvalue;
	t_vector	lightcolours;
	t_elem		pixel;
	double		i;

	light = data->lights;
	lightvalue = 0;
	lightcolours.x = 0.0;
	lightcolours.y = 0.0;
	lightcolours.z = 0.0;
	pixel = data->elem;
	while (light)
	{
		i = compose_colour(data, light, &lightvalue, pixel);
		if (i)
		{
			lightcolours.x = min_d(255, lightcolours.x + light->colour.x) * i;
			lightcolours.y = min_d(255, lightcolours.y + light->colour.y) * i;
			lightcolours.z = min_d(255, lightcolours.z + light->colour.z) * i;
		}
		light = light->next;
	}
	lightcolours = add_ambient(data, &lightvalue, lightcolours);
	colour_pixel(dst, pixel, lightvalue, lightcolours);
	return (1);
}
