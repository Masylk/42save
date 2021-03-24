/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:28:34 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/22 18:08:08 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_camera(t_camera *camera, t_data *data)
{
	int			i;
	t_camera	*tmp;

	i = 0;
	if (data->cameras)
	{
		camera->next = data->cameras;
		tmp = data->cameras;
		while (!(tmp->next == data->cameras))
		{
			data->cameras = data->cameras->next;
			i++;
		}
		data->cameras->next = camera;
	}
	else
		camera->next = camera;
	data->cameras = camera;
}
