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

int	check_shapes(t_data *data, t_ray ray)
{
	if (check_spheres(data, ray))
		return (1);
	if (check_squares(data, ray))
		return (1);
//	if (check_triangles(data, ray))
//		return (1);
//	if (check_planes(data, ray))
//		return (1);
	if (check_cylinders(data, ray))
		return (1);
	return (0);
}

void	manage_pixels(t_data *data, int x, int y)
{
	int			i;
	int			j;
	char		*dst;
	t_ray		ray;

	i = 0;
	while (i < y - 1) 
	{
		j = 0;
		while (j < x - 1)
		{
			set_ray(&ray, j, i, data);
			dst = data->curr_image.addr +
					(i * data->curr_image.line_length + j * (data->curr_image.bits_per_pixel / 8));
			if (check_shapes(data, ray))
			{
				*(unsigned int*)dst = 0x00FFFFFF;
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
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length,
			&image.endian);
	data->curr_image = image;
	manage_pixels(data, data->resolution.width, data->resolution.height);
}
