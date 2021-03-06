/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:04:07 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/22 17:55:48 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		setdata_lists(t_data *data)
{
	data->elem.pos = -1;
	data->key = -1;
	data->resolution.width = 0;
	data->resolution.height = 0;
	data->alight.colour.x = 0;
	data->alight.colour.y = 0;
	data->alight.colour.z = 0;
	data->alight.ratio = -1;
	data->cameras = NULL;
	data->lights = NULL;
	data->spheres = NULL;
	data->squares = NULL;
	data->triangles = NULL;
	data->cylindres = NULL;
	data->planes = NULL;
	return (1);
}

void	destroydata_end(t_data *data)
{
	void		*ptr;
	t_camera	*tmp;
	int			i;

	i = 0;
	tmp = data->cameras;
	while (tmp && !(data->cameras == tmp && i != 0))
	{
		ptr = (void *)tmp;
		tmp = tmp->next;
		free((t_camera *)ptr);
		i++;
	}
	data->resolution.width = 0;
	data->resolution.height = 0;
	data->alight.colour.x = 0;
	data->alight.colour.y = 0;
	data->alight.colour.z = 0;
	data->alight.ratio = 0;
	data->elem.pos = -1;
}

void	destroydata_next(t_data *data)
{
	void	*ptr;

	while (data->cylindres)
	{
		ptr = (void *)data->cylindres;
		if (data->cylindres)
			data->cylindres = data->cylindres->next;
		free((t_cyl *)ptr);
	}
	while (data->planes)
	{
		ptr = (void *)data->planes;
		if (data->planes)
			data->planes = data->planes->next;
		free((t_plane *)ptr);
	}
	while (data->lights)
	{
		ptr = (void *)data->lights;
		if (data->lights)
			data->lights = data->lights->next;
		free((t_light *)ptr);
	}
	destroydata_end(data);
}

int		destroydata(t_data *data)
{
	void	*ptr;

	while (data->spheres)
	{
		ptr = (void *)data->spheres;
		if (data->spheres)
			data->spheres = data->spheres->next;
		free((t_sphere *)ptr);
	}
	while (data->squares)
	{
		ptr = (void *)data->squares;
		if (data->squares)
			data->squares = data->squares->next;
		free((t_square *)ptr);
	}
	while (data->triangles)
	{
		ptr = (void *)data->triangles;
		if (data->triangles)
			data->triangles = data->triangles->next;
		free((t_triangle *)ptr);
	}
	destroydata_next(data);
	return (0);
}
