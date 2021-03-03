/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:07:26 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/03 17:13:26 by mtogbe           ###   ########.fr       */
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
	ray->direction.x = x - (data->resolution.width * 0.5);
	ray->direction.y = y - (data->resolution.height * 0.5);
	ray->direction.z = -((data->resolution.width) / (2 * tan(fov / 2)));
	ray->direction = normalize(ray->direction);
}

int		check_shapes(t_data *data, t_ray ray)
{
	data->elem.pos = -1;
	check_spheres(data, ray);
	check_squares(data, ray);
	check_triangles(data, ray);
	//check_planes(data, ray);
	check_cylinders(data, ray);
	if (data->elem.pos >= 0)
		return (1);
	return (0);
}

char	*compose_colour(t_data *data, char *dst)
{
	t_vector	pixel_colour;
	t_vector	normale;

	//point = add(ray.origin, mul_n(ray.direction, data->elem.pos))
	//normale = normalize(point - coor)
	//lightvalue = lightratio *dot_product(normalize(sub(poslum, point)), normale)
	//                 / dot_product(sub(poslum, point), sub(poslum, point))
	//pixel_colour = mul_n(data->elem.colour, lightvalue)
	pixel_colour = mul_n(data->elem.colour, 1);
	dst[0] = pixel_colour.x;
	dst[1] = pixel_colour.y;
	dst[2] = pixel_colour.z;
	return (dst);
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
			if (check_shapes(data, ray))
			{
				dst = compose_colour(data, dst);
			}
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
