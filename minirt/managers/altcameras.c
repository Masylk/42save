/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altcameras.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:56:11 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/10 13:57:40 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		change_camera(t_data *data)
{
	data->cameras = data->cameras->next;
	mlx_hook(data->mlxdata.win, 2, 1L << 0, keyvoid, data);
	create_new_image(data);
	mlx_hook(data->mlxdata.win, 2, 1L << 0, keypress, data);
}

int		rotate_ray(t_data *data, t_ray *ray)
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
