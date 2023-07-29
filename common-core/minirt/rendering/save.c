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

int		comp(char *n, char *m)
{
	int	i;

	i = 0;
	while (n[i] && m[i])
	{
		if (n[i] != m[i])
			return (1);
		i++;
	}
	if (n[i] || m[i])
		return (1);
	return (0);
}

void	write_bmp(char **bmp, t_data *data)
{
	int				i;
	int				j;
	int				x;
	int				y;
	unsigned char	*dst;

	dst = (unsigned char *)data->curr_image.addr;
	i = 122;
	y = data->resolution.height;
	while (y--)
	{
		x = 0;
		while (x < data->resolution.width)
		{
			j = (x * (data->curr_image.bits_per_pixel / 8))
				+ (y * data->curr_image.line_length);
			*(*bmp + i++) = *(dst + j++);
			*(*bmp + i++) = *(dst + j++);
			*(*bmp + i++) = *(dst + j);
			x++;
		}
	}
}

void	create_header(char **bmp, t_data *data, int fd)
{
	unsigned int size;

	size = data->resolution.height * data->resolution.width * 3;
	*(unsigned short *)*bmp = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(*bmp + 2) = (size + 122);
	*(unsigned int *)(*bmp + 6) = 0u;
	*(unsigned char *)(*bmp + 10) = 122;
	*(unsigned int *)(*bmp + 14) = 122 - 14;
	*(unsigned int *)(*bmp + 18) = data->resolution.width;
	*(unsigned int *)(*bmp + 22) = data->resolution.height;
	*(unsigned short *)(*bmp + 26) = 1;
	*(unsigned short *)(*bmp + 28) = 24;
	*(unsigned int *)(*bmp + 30) = 0;
	*(unsigned int *)(*bmp + 34) = (unsigned int)size;
	*(unsigned int *)(*bmp + 38) = 3780;
	*(unsigned int *)(*bmp + 42) = 3780;
	*(int *)(*bmp + 46) = 0;
	*(int *)(*bmp + 50) = 0;
	write_bmp(bmp, data);
	write(fd, *bmp, size + 122);
}

int		save_image(t_data *data, char *str)
{
	int		fd;
	int		size;
	char	*bmp;
	int		i;

	if (comp("--save", str))
		return (printf("Error : bad argument\n"));
	data->mlxdata.mlx = mlx_init();
	if (!(data->mlxdata.mlx))
		return (printf("Error : init failed\n"));
	my_mlx_pixel_put(data, data->resolution.width, data->resolution.height);
	fd = open("save.bmp", O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd <= 0)
		return (printf("Error : save file creation failed\n"));
	size = data->resolution.width * data->resolution.height * 3;
	bmp = malloc(size + 122);
	if (!bmp)
		return (printf("Error save failed\n"));
	i = 0;
	while (i < size + 122)
		bmp[i++] = 0;
	create_header(&bmp, data, fd);
	free(bmp);
	close(fd);
	return (1);
}
