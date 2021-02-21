/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:03:53 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/21 12:20:04 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_window(t_data *data)
{
	int	x;
	int	y;

	x = 1920;
	y = 1080;
	data->mlxdata.mlx = mlx_init();
	if (!(data->mlxdata.mlx))
		return (-1);
	if ((int)data->resolution.width > x)
		x = data->resolution.width;
	if ((int)data->resolution.height > y)
		y = data->resolution.height;
	data->mlxdata.win = mlx_new_window(data->mlxdata.mlx, x, y, "Namae");
	if (!(data->mlxdata.win))
		return (-1);
	return (1);
}

int	clear_mlxdata(t_mlxdata *mlxdata)
{
	free(mlxdata->mlx);
	free(mlxdata->win);
	return (0);
}

int	set_hooks(t_data *data)
{
	mlx_hook(data->mlxdata.win, 2, 1L << 0, keypress, data);
	mlx_hook(data->mlxdata.win, 3, 1L << 1, keyrelease, data);
	return (1);
}

int	create_image(t_data *data)
{
	(void)data;
	return (1);
}