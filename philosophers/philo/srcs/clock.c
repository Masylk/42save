#include "philosophers.h"

void	print_timestamp(int ms)
{
	ft_putstr_fd("[", 1);
	ft_putnbr_fd(ms, 1);
	ft_putendl_fd(" ms]", 1);
}

void	*ft_clock(void *args)
{
	unsigned int	start_time;
	unsigned int	cur_time;
	unsigned int	pstart_time;
	struct timeval	tm;
	t_vars		*vars;

	vars = (t_vars *)args;
	(void)vars;
	gettimeofday(&tm, NULL);
	start_time = ((unsigned int)tm.tv_sec * 1000) + ((unsigned int)tm.tv_usec / 1000);
	pstart_time = start_time;
	while (!vars->philo_end)
	{
		gettimeofday(&tm, NULL);
		cur_time = ((unsigned int)tm.tv_sec * 1000) + ((unsigned int)tm.tv_usec / 1000);
		if (cur_time - start_time >= 5)
		{
			print_timestamp((int)((cur_time - pstart_time)));
			start_time = cur_time;
		}
	}
	return (vars);
}
