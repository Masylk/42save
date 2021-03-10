/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:28:52 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/10 16:10:03 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_res(unsigned int *n, char *str)
{
	*n = ft_atoi(str);
	if (*n <= 0)
		return (0);
	if (ft_nblen(*n) != (int)ft_strlen(str))
		return (0);
	return (1);
}

int	parse_camera(t_data *data, char *line)
{
	t_camera	*camera;
	char		**tab;

	tab = ft_split(line, ' ');
	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (freetab(tab, 0));
	if (ft_tablen(tab) != 4)
		return (freetab(tab, 0));
	if (!(get_point(tab[1], &(camera->coor))))
		return (freetab(tab, 0));
	if (!(get_point(tab[2], &(camera->v))))
		return (freetab(tab, 0));
	if (!(get_double(&(camera->fov), tab[3])))
		return (freetab(tab, 0));
	camera->next = data->cameras;
	if (data->cameras)
		data->cameras->next = camera;
	data->cameras = camera;
	return (freetab(tab, 1));
}

int	parse_alight(t_data *data, char *line)
{
	t_alight	alight;
	char		**tab;

	if (data->alight.ratio != -1)
		return (0);
	tab = ft_split(line, ' ');
	if (ft_tablen(tab) != 3)
		return (freetab(tab, 0));
	if (!(get_point(tab[2], &(alight.colour))))
		return (freetab(tab, 0));
	if (!(get_double(&(alight.ratio), tab[1])))
		return (freetab(tab, 0));
	data->alight = alight;
	return (freetab(tab, 1));
}

int	parse_res(t_data *data, char *line)
{
	t_resolution	res;
	char			**tab;

	if (data->resolution.width != 0)
		return (0);
	tab = ft_split(line, ' ');
	if (ft_tablen(tab) != 3)
		return (freetab(tab, 0));
	if (!(get_res(&(res.width), tab[1])))
		return (freetab(tab, 0));
	if (!(get_res(&(res.height), tab[2])))
		return (freetab(tab, 0));
	data->resolution.width = res.width;
	data->resolution.height = res.height;
	return (freetab(tab, 1));
}

int	parse_light(t_data *data, char *line)
{
	t_light	*light;
	char	**tab;

	tab = ft_split(line, ' ');
	if (ft_tablen(tab) != 4)
		return (freetab(tab, 0));
	light = malloc(sizeof(t_light));
	if (!light)
		return (freetab(tab, 0));
	if (!(get_point(tab[1], &(light->coor))))
		return (freetab(tab, 0));
	if (!(get_point(tab[3], &(light->colour))))
		return (freetab(tab, 0));
	if (!(get_double(&(light->ratio), tab[2])))
		return (freetab(tab, 0));
	light->next = data->lights;
	data->lights = light;
	return (freetab(tab, 1));
}
