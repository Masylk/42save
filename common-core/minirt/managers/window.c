/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:03:53 by mtogbe            #+#    #+#             */
/*   Updated: 2021/04/14 18:10:39 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_window(t_data *data)
{
	int	x;
	int	y;
	int	maxh;
	int	maxw;

	maxh = 1080;
	maxw = 1920;
	data->mlxdata.mlx = mlx_init();
//	mlx_get_screen_size(data->mlxdata.mlx, &maxw, &maxh);
	x = max_d(1, min_d(maxw, data->resolution.width));
	y = max_d(1, min_d(maxh, data->resolution.height));
	data->resolution.width = x;
	data->resolution.height = y;
	if (!(data->mlxdata.mlx))
		return (-1);
	data->mlxdata.win = mlx_new_window(data->mlxdata.mlx, x, y, "Namae");
	if (!(data->mlxdata.win))
		return (-1);
	return (1);
}

int	clear_mlxdata(t_mlxdata mlxdata)
{
	free(mlxdata.mlx);
	return (0);
}

int	resize(t_data *data)
{
	mlx_clear_window(data->mlxdata.mlx, data->mlxdata.win);
	mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->curr_image.img, 0, 0);
	return (1);
}

int	set_hooks(t_data *data)
{
	mlx_hook(data->mlxdata.win, 2, 1L << 0, keypress, data);
	mlx_hook(data->mlxdata.win, 3, 1L << 1, keyrelease, data);
	mlx_hook(data->mlxdata.win, 17, 1L << 17, quit_process, data);
	mlx_hook(data->mlxdata.win, 33, 1L << 17, quit_process, data);
	mlx_hook(data->mlxdata.win, 15, 1L << 16, resize, data);
	return (1);
}

int	create_image(t_data *data)
{
	(void)data;
	return (1);
}
