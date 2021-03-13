/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:48:15 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/12 14:52:26 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_rayshadow(t_data *data, t_ray *ray, t_light *light)
{
	ray->direction = normalize(sub(light->coor,
				data->elem.point));
	ray->origin = add(data->elem.point, mul_n(ray->direction, 0.1));
}

//ca c'est bon
void	colour_pixel(unsigned char *dst, t_elem pixel, double lightvalue, t_vector lights)
{
	t_vector	pixel_colour;

	pixel_colour.x = min_d(255, max_d(lights.x, pixel.colour.x));
	pixel_colour.y = min_d(255, max_d(lights.y, pixel.colour.y));
	pixel_colour.z = min_d(255, max_d(lights.z,  pixel.colour.z));
	pixel_colour = mul_n(pixel_colour, lightvalue);
	dst[0] = min_d(255, max_d(0.0, pixel_colour.z) );//* (1.0 / 2.2));
	dst[1] = min_d(255, max_d(0.0, pixel_colour.y) );//* (1.0 / 2.2));
	dst[2] = min_d(255, max_d(0.0, pixel_colour.x) );//* (1.0 / 2.2));
}

//à refaire
int		compose_colour(t_data *data, t_light *light, double *lightvalue)
{
	t_ray		rayshadow;
	t_vector	dist;
	int			ret;
	t_elem		pixel;

	set_rayshadow(data, &rayshadow, light);
	pixel = data->elem;
	ret = check_shapes(data, rayshadow);
	dist = normalize(sub(light->coor, pixel.point));
	if (ret && (data->elem.pos * data->elem.pos) < dot_product(dist, dist))
		return (0);
	*lightvalue = min_d(1.0, ((*lightvalue) + (light->ratio * 5.3 *
			max_d(0.0, dot_product(dist, normalize(pixel.normale)))
			/ dot_product(dist, dist) * (1.0 / 2.2))) * 0.5);
	return (1);
}

//ca ca marche
void	add_ambient(t_data *data, unsigned char *dst)
{
	t_vector	colour;

	colour = mul_n(data->alight.colour, data->alight.ratio);
	dst[0] = min_d(255, (dst[0] + max_d(0, colour.x) * (1 / 2.2)));
	dst[1] = min_d(255, (dst[1] + max_d(0, colour.y) * (1 / 2.2)));
	dst[2] = min_d(255, (dst[2] + max_d(0, colour.z) * (1 / 2.2)));	
}

//à refaire
int		check_lights(t_data *data, unsigned char *dst)
{
	t_light		*light;
	double		lightvalue;
	t_vector	lightcolours;
	t_elem		pixel;

	light = data->lights;
	pixel = data->elem;
	lightvalue = 0.0;
	lightcolours.x = 0.0;
	lightcolours.y = 0.0;
	lightcolours.z = 0.0;
	while(light)
	{
		if (compose_colour(data, light, &lightvalue))
		{
			lightcolours.x = min_d(255, lightcolours.x + light->colour.x);
			lightcolours.y = min_d(255, lightcolours.y + light->colour.y);
			lightcolours.z = min_d(255, lightcolours.z + light->colour.z);
		}
		light = light->next;
	}
	colour_pixel(dst, pixel, lightvalue, lightcolours);
//	add_ambient(data, dst);
	return (1);
}

