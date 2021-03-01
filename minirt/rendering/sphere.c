#include "minirt.h"

int	check_spheres(t_data *data, t_ray ray)
{
	t_sphere	*tmp;

	tmp = data->spheres;
	while (tmp)
	{
		if (check_sphere(tmp, ray))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sphere(t_sphere *sphere, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	double		r;
	double		delta;
	t_vector	d;

	d = sub(ray.origin, sphere->coor);
	r = sphere->width * 0.5;
	a = dot_product(ray.direction, ray.direction);
	b = 2 * dot_product(ray.direction, d);
	c = dot_product(d, d) - r * r;
	delta =  b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	delta = sqrt(delta);
	a = 2 * a;
	if (((-b + delta) / a) > 0)
		return (1);
	return (0);
}
