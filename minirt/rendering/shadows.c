/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:48:15 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/21 15:36:13 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_rayshadow(t_elem pixel, t_ray *ray, t_light *light)
{
	ray->direction = normalize(sub(light->coor,
				pixel.point));
	ray->origin = add(pixel.point, mul_n(ray->direction, 0.01));
}

void	colour_pixel(unsigned char *d, t_vector hitcolour)
{
	d[0] = min_d(255, max_d(0.0, hitcolour.z)) * 1 / 2.2;
	d[1] = min_d(255, max_d(0.0, hitcolour.y)) * 1 / 2.2;
	d[2] = min_d(255, max_d(0.0, hitcolour.x)) * 1 / 2.2;
}

t_vector	compose_colour(t_data *data, t_light *light, t_elem p)
{
	t_ray		rayshadow;
	t_vector	dist;
	int			ret;
	t_vector	i;

	i.x = 0;
	i.y = 0;
	i.z = 0;
	set_rayshadow(p, &rayshadow, light);
	dist = sub(light->coor, p.point);
	ret = check_shapes(data, rayshadow);
	if (ret && (data->elem.pos * data->elem.pos) < dot_product(dist, dist))
		return (i);
	i = mul_n(light->colour, light->ratio * 100
			/ (4 * M_PI * dot_product(dist, dist)));
	i = mul_n(mul(i, p.colour), max_d(0, dot_product(normalize(dist), p.normale)));
	return (i);
}

t_vector	add_ambient(t_data *data, t_vector lcolours)
{
	t_vector	colour;

	colour = mul_n(data->alight.colour, data->alight.ratio);
	lcolours.x = min_d(255, (lcolours.x + max_d(0, colour.x)));
	lcolours.y = min_d(255, (lcolours.y + max_d(0, colour.y)));
	lcolours.z = min_d(255, (lcolours.z + max_d(0, colour.z)));
	return (lcolours);
}

int		check_lights(t_data *data, unsigned char *dst)
{
	t_light		*light;
	t_vector	hitcolour;
	t_elem		pixel;
	t_vector	intensity;

	light = data->lights;
	pixel = data->elem;
	while (light)
	{
		intensity = compose_colour(data, light, pixel);
		hitcolour = add(hitcolour, intensity);
		light = light->next;
	}
	hitcolour = add_ambient(data, hitcolour);
	colour_pixel(dst, hitcolour);
	return (1);
}
