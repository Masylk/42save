/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:35:21 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/10 17:07:20 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	quit_process(t_data *data)
{
	printf("EXIT");
	mlx_destroy_image(data->mlxdata.mlx, data->curr_image.img);
	mlx_destroy_window(data->mlxdata.mlx, data->mlxdata.win);
	destroydata(data);
	exit(0);
	return (1);
}

//mettre des pointeurs sur fonction dans data qui pointent vers ces fonctions
//quand une fonction qui demande un long chargement est appelé
//mettre le pointeur sur fonction à Null pour empêcher l'exécution multiple
//de la fonction

int	keyvoid(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	return (1);
}

int	keypress(int keycode, t_data *data)
{
	if (keycode != data->key)
	{
		data->key = keycode;
		if (keycode == ESC)
			quit_process(data);
		if (keycode == SPACE)
			change_camera(data);
	}
	return (1);
}

int	keyrelease(int keycode, t_data *data)
{
	if (data->key == keycode)
		data->key = -1;
	return (1);
}
