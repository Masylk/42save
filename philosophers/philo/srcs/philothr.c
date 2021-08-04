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

int	eat_state(t_philo *philo, int id)
{
	int	time_ms;

	time_ms = philo->vars->cur_time - philo->vars->start_time;
	if (philo->fleft != philo->fright
			&& get_forks(philo->vars, philo->fleft, philo->fright))
	{
		print_message(id, time_ms, " has taken a fork");
		print_message(id, time_ms, " has taken a fork");
		print_message(id, time_ms, " is eating");
		philo->goal = philo->goal + 1;
		philo->eating = 1;
		philo->prev_mealtime = philo->vars->cur_time;
		if (philo->sleeping)
			philo->sleeping = 0;
		else if (philo->thinking)
			philo->thinking = 0;
		return (1);
	}
	if (philo->sleeping)
		return (think_state(philo, id));
	return (1);
}

int	sleep_state(t_philo *philo, int id)
{
	int	time_ms;

	time_ms = philo->vars->cur_time - philo->vars->start_time;
	print_message(id, time_ms, " is sleeping");
	get_forks_back(philo->vars, philo->fleft, philo->fright);
	philo->eating = 0;
	philo->sleeping = 1;
	philo->prev_time = philo->vars->cur_time;
	return (1);
}

int	think_state(t_philo *philo, int id)
{
	int	time_ms;

	time_ms = philo->vars->cur_time - philo->vars->start_time;
	print_message(id, time_ms, " is thinking");
	philo->sleeping = 0;
	philo->thinking = 1;
	return (1);
}

unsigned int	handle_state(t_philo *philo, t_vars *vars)
{
	unsigned int	next_timer;
	int		id;

	id = philo->id;
	next_timer = 1;
	if (philo->vars->cur_time - philo->prev_mealtime >= vars->die_time)
	{
		print_message(philo->id, vars->cur_time - vars->start_time,
				" died");
		vars->philo_end = 1;
		return (-1);
	}
	if ((philo->sleeping && vars->cur_time - philo->prev_time
				>= vars->sleep_time)
			|| philo->thinking)
		next_timer = eat_state(philo, id);
	else if (philo->eating)
		next_timer = sleep_state(philo, id);
	if (vars->die_time < next_timer)
		next_timer = vars->die_time;
	return (next_timer);
}

int	choose_sleep(t_philo *philo)
{
	if(philo->eating)
		return (philo->vars->eat_time * 1000);
	return (10);
}

void	*philo_life(void *args)
{
	t_vars		*vars;
	t_philo		*philo;
	unsigned int	prev_time;
	int		next_timer;
	int		time;

	philo = (t_philo *)args;
	vars = philo->vars;
	prev_time = vars->start_time;
	next_timer = 0;
	philo->prev_time = prev_time;
	while (prev_time && !vars->philo_end)
	{
		usleep(10);
		pthread_mutex_lock(&vars->mutex);
		time = vars->cur_time - prev_time;
		if (time >= next_timer && !vars->philo_end)
		{
			prev_time = vars->cur_time;
			next_timer = handle_state(philo, vars);
			if (next_timer < 0)
				prev_time = 0;
		}
		pthread_mutex_unlock(&vars->mutex);
		usleep(choose_sleep(philo));
	}
	return (NULL);
}
