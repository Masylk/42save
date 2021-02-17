/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:25:58 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/17 15:28:28 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int				keypress(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	printf("%d\n", keycode);
	return (0);
}

int				keyrelease(int keycode, t_vars *vars)
{
	(void)vars;
	printf("%d\n", keycode);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_vars	vars;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	if (!mlx_win)
		return (0);
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FFFF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	vars.win = mlx_win;
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	mlx_hook(vars.win, 3, 1L << 1, keyrelease, &vars);
	mlx_loop(mlx);
}
