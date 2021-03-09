/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:07:26 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/05 17:12:54 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_ray(t_ray *ray, int x, int y, t_data *data)
{
	double	fov;

	ray->origin.x = data->cameras->coor.x;
	ray->origin.y = data->cameras->coor.y;
	ray->origin.z = data->cameras->coor.z;
	fov = data->cameras->fov * (M_PI / 180);
	ray->direction.x = (x - (data->resolution.width * 0.5));
	ray->direction.y = -(y - (data->resolution.height * 0.5));
	ray->direction.z = -((data->resolution.width) / (2 * tan(fov * 0.5)));
	rotate_ray(data, ray);
	ray->direction = normalize(ray->direction);
}

int		check_shapes(t_data *data, t_ray ray)
{
	data->elem.pos = -1;
	check_cylinders(data, ray);
	check_spheres(data, ray);
	check_squares(data, ray);
	check_triangles(data, ray);
	check_planes(data, ray);
	if (data->elem.pos >= 0)
		return (1);
	return (0);
}

void	manage_pixels(t_data *data, int x, int y)
{
	int				i;
	int				j;
	char			*dst;
	t_ray			ray;

	i = 0;
	while (i < y - 1)
	{
		j = 0;
		while (j < x - 1)
		{
			set_ray(&ray, j, i, data);
			dst = data->curr_image.addr +
				(i * data->curr_image.line_length
				 + j * (data->curr_image.bits_per_pixel / 8));
			dst[0] = 0;
			dst[1] = 0;
			dst[2] = 0;
			if (check_shapes(data, ray))
				check_lights(data, ray, dst);
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y)
{
	t_img	image;

	image.img = mlx_new_image(data->mlxdata.mlx, x, y);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	data->curr_image = image;
	manage_pixels(data, data->resolution.width, data->resolution.height);
}
