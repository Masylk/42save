#include "minirt.h"

void	add_camera(t_camera *camera, t_data *data)
{
	int			i;
	t_camera	*tmp;

	i = 0;
	if (data->cameras)
	{
		camera->next = data->cameras;
		tmp = data->cameras;
		while (!(tmp->next == data->cameras))
		{
			data->cameras = data->cameras->next;
			i++;
		}
		data->cameras->next = camera;
	}
	else
		camera->next = camera;
	data->cameras = camera;
}
