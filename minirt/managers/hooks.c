/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:35:21 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/21 13:17:00 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		quit_process(t_data *data)
{
	printf("EXIT");
	mlx_destroy_image(data->mlxdata.mlx, data->curr_image.img);
	mlx_destroy_window(data->mlxdata.mlx, data->mlxdata.win);
//	mlx_destroy_display(data->mlxdata.mlx);
	clear_mlxdata(data->mlxdata);
	destroydata(data);
	exit(0);
	return (1);
}

void	check_movement(int keycode, t_data *data)
{
	if (keycode == D)
	{
		data->cameras->coor = add(data->cameras->coor,
				mul_n(data->cameras->right, MOVESPEED));
		create_new_image(data);
	}
	else if (keycode == A)
	{
		data->cameras->coor = sub(data->cameras->coor,
				mul_n(data->cameras->right, MOVESPEED));
		create_new_image(data);
	}
	else if (keycode == W)
	{
		data->cameras->coor = add(data->cameras->coor,
				mul_n(data->cameras->forward, MOVESPEED));
		create_new_image(data);
	}
	else if (keycode == S)
	{
		data->cameras->coor = sub(data->cameras->coor,
				mul_n(data->cameras->forward, MOVESPEED));
		create_new_image(data);
	}
}

void	check_look(int keycode, t_data *data)
{
	if (keycode == RIGHT)
	{
		data->cameras->v.x -= ROTSPEED;
		create_new_image(data);
	}
	else if (keycode == LEFT)
	{
		data->cameras->v.x += ROTSPEED;
		create_new_image(data);
	}
	else if (keycode == UP)
	{
		data->cameras->v.y += ROTSPEED;
		create_new_image(data);
	}
	else if (keycode == DOWN)
	{
		data->cameras->v.y -= ROTSPEED;
		create_new_image(data);
	}
	else
		check_movement(keycode, data);
}

int		keypress(int keycode, t_data *data)
{
	if (keycode != data->key)
	{
		data->key = keycode;
		if (keycode == ESC)
			quit_process(data);
		else if (keycode == SPACE)
			change_camera(data);
		else
			check_look(keycode, data);
	}
	return (1);
}

int		keyrelease(int keycode, t_data *data)
{
	if (data->key == keycode)
		data->key = -1;
	return (1);
}
