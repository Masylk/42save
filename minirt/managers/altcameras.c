#include "minirt.h"

void	set_mat(t_data *data, t_vector f, t_vector r, t_vector u)
{
	data->cam_mat[0][0] = r.x;
	data->cam_mat[0][1] = r.y;
	data->cam_mat[0][2] = r.z;
	data->cam_mat[1][0] = u.x;
	data->cam_mat[1][1] = u.y;
	data->cam_mat[1][2] = u.z;
	data->cam_mat[2][0] = f.x;
	data->cam_mat[2][1] = f.y;
	data->cam_mat[2][2] = f.z;
	data->cam_mat[3][0] = data->cameras->coor.x;
	data->cam_mat[3][1] = data->cameras->coor.y;
	data->cam_mat[3][2] = data->cameras->coor.z;
}

int	rotate_ray(t_data *data, t_ray *ray)
{
	t_vector	forward;
	t_vector	right;
	t_vector	up;
	t_vector	tmp;

	forward = normalize(data->cameras->v);
	tmp.x = forward.y;
	tmp.y = forward.z;
	tmp.z = forward.x;
	right = cross_product(normalize(tmp), forward);
	up = cross_product(forward, right);
	ray->direction.x = ray->direction.x * right.x
		+ ray->direction.y * up.x
		+ ray->direction.z * forward.x;
	ray->direction.y = ray->direction.x * right.y
		+ ray->direction.y * up.y
		+ ray->direction.z * forward.y;
	ray->direction.z = ray->direction.x * right.z
		+ ray->direction.y * up.z
		+ ray->direction.z * forward.z;
	return (1);
}
