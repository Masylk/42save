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
	/ (dot_product(dist, dist) * (1/2.2));
	pixel_colour = mul_n(pixel.colour, lightvalue);
	dst[0] += min_d(255, max_d(0, pixel_colour.z)) * (1/2.2);
	dst[1] += min_d(255, max_d(0, pixel_colour.y) * (1/2.2));
	dst[2] += min_d(255, max_d(0, pixel_colour.x) * (1/2.2));
}

int	compose_colour(t_data *data, char *dst)
{
	t_elem		pixel;
	t_ray		rayshadow;
	t_vector	dist;
	int		ret;

	dist = data->elem.point;
	pixel = data->elem;
	set_rayshadow(data, &rayshadow);
	ret = check_shadow(data, rayshadow);
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

int             check_shadow(t_data *data, t_ray ray)
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
