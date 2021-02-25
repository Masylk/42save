#include "minirt.h"

int	check_plane(t_plane *plane, t_ray ray)
{
	double	denom;
	double	dist;

	denom = dot_product(ray.direction, plane->v);
	if (denom == 0)
		return (0);
	dist = dot_product(sub(plane->coor, ray.origin), plane->v) / denom;
	if (dist < 0)
		return (0);
	return (1);
}

int	check_planes(t_data *data, t_ray ray)
{
	t_plane	*tmp;

	tmp = data->planes;
	while (tmp)
	{
		if (check_plane(tmp, ray))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
