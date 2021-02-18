/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:04:07 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/18 17:02:18 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	setdata_lists(t_data *data)
{
	data->cameras = NULL;
	data->lights = NULL;
	data->spheres = NULL;
	data->squares = NULL;
	data->triangles = NULL;
	data->cylindres = NULL;
	data->planes = NULL;
	return (1);
}
