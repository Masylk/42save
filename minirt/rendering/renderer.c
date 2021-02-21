#include "minirt.h"

void            manage_pixels(t_data *data, int x, int y)
{
    int     i;
    int     j;
    char    *dst;

    i = 0;
    while (i < y - 1) 
    {
        while (j < x - 1)
        {
            dst = data->curr_image + 
            (j * data->curr_image.line_length + i * (data->curr_image.bits_per_pixel / 8));
            j++;
        }
        i++;
    }
}

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
    t_img   image;

    image.img = mlx_new_image(data->mlxdata.mlx, x, y);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length,
			&image.endian);
	dst = image.addr + (5 * image.line_length + 5 * (image.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
    data->curr_image = image;
}