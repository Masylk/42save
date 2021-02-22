#include "minirt.h"

void	set_ray(t_ray *ray, int x, int y, t_data *data)
{
	double	fov;

	ray->origin.x = 0;
	ray->origin.y = 0;
	ray->origin.z = 0;
	fov = data->cameras->fov * (M_PI / 180);
	ray->direction.x = x - data->resolution.width / 2;
	ray->direction.y = y - data->resolution.height / 2;
	ray->direction.z = -data->resolution.width / (2 * tan(fov / 2));
	ray->direction = normalize(ray->direction);
}

int		check_spheres(t_data *data, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	r;
	double	delta;

	r = data->spheres->width / 2;
	a = 1;
	b = 2 * dot_product(ray.direction, sub(ray.origin, data->spheres->coor));
	c = get_length(sub(ray.origin, data->spheres->coor)) - r * r;
	delta =  b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	if (((-b + sqrt(delta)) / (2 * a)) > 0)
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
			if (check_spheres(data, ray))
			{
				//printf()
				*(unsigned int*)dst = 0x00FFFFFF;
				j++;
			}
			else
				*(unsigned int*)dst = 0x00FFFF00;
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