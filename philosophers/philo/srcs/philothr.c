#include "philosophers.h"

void	print_message(int nb, unsigned int time, char *msg)
{
	ft_putstr_fd("[", 1);
	ft_putnbr_fd(time, 1);
	ft_putstr_fd(" ms] : ", 1);
	ft_putstr_fd("Philosopher ", 1);
	ft_putnbr_fd(nb, 1);
	ft_putstr_fd(msg, 1);
	ft_putendl_fd("", 1);
}

void	*philo_life(void *args)
{
	t_vars		*vars;
	t_philo		*list;
	unsigned int	prev_time;
	int		id;

	list = (t_philo *)args;
	id = list->id;
	vars = list->vars;
	prev_time = vars->start_time;
	while (prev_time)
	{
		pthread_mutex_lock(&vars->mutex);
		if (vars->cur_time - prev_time >= (unsigned int)vars->die_time)
		{
			print_message(id, vars->cur_time - vars->start_time,
				" dead");
			prev_time = vars->cur_time;
		}
		pthread_mutex_unlock(&vars->mutex);
		usleep(100);
	}
	return (NULL);
}
