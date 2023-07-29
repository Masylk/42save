/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altcameras.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:56:11 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/17 15:23:17 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		change_camera(t_data *data)
{
	data->cameras = data->cameras->next;
	create_new_image(data);
}

t_vector	init_tmp(t_vector forward)
{
	t_vector tmp;

	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	if (forward.y == 1 || forward.y == -1)
		tmp.x = 1;
	else
		tmp.y = 1;
	return (tmp);
}

int			rotate_ray(t_data *data, t_ray *ray)
{
	t_vector	forward;
	t_vector	right;
	t_vector	up;
	t_vector	tmp;

	forward = normalize(data->cameras->v);
	tmp = init_tmp(forward);
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
	data->cameras->forward = forward;
	data->cameras->right = right;
	data->cameras->up = up;
	return (1);
}
