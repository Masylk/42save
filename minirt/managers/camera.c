#include "minirt.h"

t_vector        rotate_z(t_vector direction, t_vector v, t_vector axis)
{
	axis.y = 0;
	axis.x = 1;
	axis.z = 0;

	if (direction.z != 0.0)
		v = add(add(mul_n(v, cos(M_PI * direction.z)),
			mul_n(axis, (1 - cos(M_PI * direction.z)) *
			dot_product(axis, v))),
			mul_n(cross_product(axis, v),
			sin(M_PI * direction.z)));
	return (v);
}


t_vector	rotate_y(t_vector direction, t_vector v, t_vector axis)
{
	axis.y = 0;
	axis.x = 0;
	axis.z = 1;

	if (direction.y != 0.0)
		v = add(add(mul_n(v, cos(M_PI * direction.y)),
			mul_n(axis, (1 - cos(M_PI * direction.y)) *
			dot_product(axis, v))),
			mul_n(cross_product(axis, v),
			sin(M_PI * direction.y)));
	v = normalize(v);
	return (v);
}

int	rotate(t_data *data, t_ray *ray)
{
	t_vector	direction;
	t_vector	v;
	t_vector	axis;

	axis.x = 0;
	axis.y = 1;
	axis.z = 0;
	direction = data->cameras->v;
	v = add(add(mul_n(ray->direction, cos(M_PI * -direction.x)),
			mul_n(axis, (1 - cos(M_PI * -direction.x)) *
			dot_product(axis, ray->direction))),
			mul_n(cross_product(axis, ray->direction),
			sin(M_PI * -direction.x)));
	v = normalize(v);
	v = rotate_y(direction, v, axis);
	v = rotate_z(direction, v, axis);
	ray->direction = v;
	ray->direction = normalize(ray->direction);
	return (1);
}
