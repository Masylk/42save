#include "philosophers.h"

void	*philo_life(void *args)
{
	t_vars		*vars;
	t_philo		*list;
	unsigned int	prev_time;

	(void)list;
	vars = (t_vars *)args;
	list = vars->plist;
	prev_time = vars->start_time;
	while (prev_time)
	{
		pthread_mutex_lock(&vars->mutex);
		if (vars->cur_time - prev_time >= 1000)
		{
		//	printf("%u\n", vars->cur_time - vars->start_time);
			print_timestamp((int)((vars->cur_time - vars->start_time)));
			prev_time = vars->cur_time;
		}
		pthread_mutex_unlock(&vars->mutex);
		usleep(100);
	}
	//debug_philo(list);
	return (NULL);
}
