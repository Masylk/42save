/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:35:21 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/04 13:13:34 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	quit_process(t_data *data)
{
	printf("EXIT");
	mlx_destroy_window(data->mlxdata.mlx, data->mlxdata.win);
	destroydata(data);
	exit (0);
	return (1);
}

int	keypress(int keycode, t_data *data)
{
	if(keycode != data->key)
	{
		printf("key\n");
		data->key = keycode;
		if (keycode == 53)
			quit_process(data);
	}
	return (1);
}

int	keyrelease(int keycode, t_data *data)
{
	(void)keycode;
	data->key = -1;
	return (1);
}
