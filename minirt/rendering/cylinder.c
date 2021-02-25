#include "minirt.h"

int	check_cylinder(t_cyl *cyl, t_ray ray)
{
	(void)cyl;
	(void)ray;
	return (0);
}

int	check_cylinders(t_data *data, t_ray ray)
{
	t_cyl	*tmp;

	tmp = data->cylindres;
	while(tmp)
	{
		if (check_cylinder(tmp, ray))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

