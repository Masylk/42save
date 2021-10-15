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

void	*check_death(void *args)
{
	t_vars	*vars;
	
	vars = (t_vars *)args;
	sem_wait(vars->sem_death);
	vars->philo_end = 1;
	sem_post(vars->sem_death);
	sem_post(vars->sem_end);
	free_philo(vars->plist);
	return (NULL);
}

void	*check_end(void *args)
{
	t_vars	*vars;
	int	count;

	count = 0;
	vars = (t_vars *)args;
	while (count != vars->nb)
	{
		sem_wait(vars->sem_end);
		count++;
	}
	vars->philo_end = 1;
	sem_post(vars->sem_goal);
	return (NULL);
}

void	*check_meals(void *args)
{
	t_vars	*vars;
	int	count;

	count = 0;
	vars = (t_vars *)args;
	if (vars->eat_goal < 0)
		return (NULL);
	while (count != vars->nb && !vars->philo_end)
	{
		sem_wait(vars->sem_goal);
		count++;
	}
	if (count == vars->nb)
		sem_post(vars->sem_death);
	return (NULL);
}

void	*ft_clock(void *args)
{
	t_vars		*vars;
	t_philo		*philo;

	vars = (t_vars *)args;
	philo = vars->plist;
	while (!vars->philo_end)
	{
		get_time(&vars->cur_time);
		sem_wait(vars->sem_turn);
		sem_wait(vars->sem_clock);
		if (philo->vars->cur_time - philo->prev_mealtime >= vars->die_time)
		{
			print_message(philo->id, vars->cur_time - vars->start_time,
				" died");
			vars->philo_end = 1;
			sem_post(vars->sem_death);
			continue ;
		}
		sem_post(vars->sem_clock);
		sem_post(vars->sem_turn);
		usleep(10);
	}
	return (vars);
}
