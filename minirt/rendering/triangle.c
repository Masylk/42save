#include "minirt.h"

int	is_inside(t_triangle *triangle, t_vector normale, t_vector point)
{
	t_vector	edge;
	t_vector	pos;

	edge = sub(triangle->coor_b, triangle->coor_a);
	pos = sub(point, triangle->coor_a);
	if (dot_product(normale, cross_product(edge, pos)) < 0)
		return (0);
	edge = sub(triangle->coor_c, triangle->coor_b);
        pos = sub(point, triangle->coor_b);
        if (dot_product(normale, cross_product(edge, pos)) < 0)
                return (0);
	edge = sub(triangle->coor_a, triangle->coor_c);
        pos = sub(point, triangle->coor_c);
        if (dot_product(normale, cross_product(edge, pos)) < 0)
                return (0);
	printf("inside");
	return (1);
}

int	check_triangle(t_triangle *triangle, t_ray ray)
{
	t_vector	normale;
	t_vector	point;
	double		a;
	double		dist;
	double		t;

	normale = cross_product(
			sub(triangle->coor_c, triangle->coor_a),
			sub(triangle->coor_b, triangle->coor_a));
	a = dot_product(normale, ray.direction);
	if (a == 0)
		return (0);
	dist = dot_product(normale, triangle->coor_a);
	t = (dot_product(normale, ray.origin) + dist) / a;
	if (t < 0)
		return (0);
	printf("infront");
	point = add(ray.origin, mul_n(ray.direction, t));
	if (is_inside(triangle, normale, point))
		return (1);
	return (0);
}

int	check_triangles(t_data *data, t_ray ray)
{
	t_triangle	*tmp;

	tmp = data->triangles;
	while (tmp)
	{
		if (check_triangle(tmp, ray))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
