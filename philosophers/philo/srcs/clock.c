#include "philosophers.h"

void	print_timestamp(int ms)
{
	ft_putstr_fd("[", 1);
	ft_putnbr_fd(ms, 1);
	ft_putendl_fd(" ms]", 1);
}

void	get_time(unsigned int *t)
{
	struct timeval	tm;
	
	gettimeofday(&tm, NULL);
	*t = ((unsigned int)tm.tv_sec * 1000) + ((unsigned int)tm.tv_usec / 1000);
}

void	*ft_clock(void *args)
{
	t_vars		*vars;

	vars = (t_vars *)args;
	while (!vars->philo_end)
	{
		pthread_mutex_lock(&vars->mutex);
		get_time(&vars->cur_time);
		pthread_mutex_unlock(&vars->mutex);
		usleep(10);
	}
	return (vars);
}
