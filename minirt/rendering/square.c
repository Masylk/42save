#include "minirt.h"

int	check_square(t_square *square, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	t_vector	dist;
	double		area;

	a = dot_product(sub(ray.origin, square->coor), square->v);
	b = dot_product(ray.direction, square->v);
	if (b == 0 || (a > 0 && b > 0) || (a < 0 && b < 0))
		return (0);
	c = -(a / b);
	area = square->width * 0.5;
	dist = sub(add(mul_n(ray.direction, c), ray.origin), square->coor);
	if (fabs(dist.x) > area || fabs(dist.y) > area || fabs(dist.z) > area)
		return (0);
	if (c > 0)
		return (1);
	return (0);
}

int	check_squares(t_data * data, t_ray ray)
{
	t_square	*tmp;

	tmp = data->squares;
	while (tmp)
	{
		if (check_square(tmp, ray))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
