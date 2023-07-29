/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philothr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:50:27 by mtogbe            #+#    #+#             */
/*   Updated: 2021/11/24 19:08:32 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eat_state(t_philo *philo, int id)
{
	int	time_ms;

	if (philo->sleeping)
		think_state(philo, philo->id);
	sem_wait(philo->vars->sem_forks);
	sem_wait(philo->vars->sem_turn);
	time_ms = philo->vars->cur_time - philo->vars->start_time;
	print_message(id, time_ms, " has taken a fork");
	sem_post(philo->vars->sem_turn);
	sem_wait(philo->vars->sem_forks);
	sem_wait(philo->vars->sem_turn);
	time_ms = philo->vars->cur_time - philo->vars->start_time;
	print_message(id, time_ms, " has taken a fork");
	print_message(id, time_ms, " is eating");
	philo->goal = philo->goal + 1;
	if (philo->goal == philo->vars->eat_goal)
		sem_post(philo->vars->sem_goal);
	philo->eating = 1;
	philo->prev_mealtime = philo->vars->cur_time;
	if (philo->sleeping)
		philo->sleeping = 0;
	else if (philo->thinking)
		philo->thinking = 0;
	sem_post(philo->vars->sem_turn);
	return (1);
}

int	sleep_state(t_philo *philo, int id)
{
	int	time_ms;

	sem_post(philo->vars->sem_forks);
	sem_post(philo->vars->sem_forks);
	sem_wait(philo->vars->sem_turn);
	time_ms = philo->vars->cur_time - philo->vars->start_time;
	print_message(id, time_ms, " is sleeping");
	philo->eating = 0;
	philo->sleeping = 1;
	philo->prev_time = philo->vars->cur_time;
	sem_post(philo->vars->sem_turn);
	return (1);
}

int	think_state(t_philo *philo, int id)
{
	int	time_ms;

	sem_wait(philo->vars->sem_turn);
	time_ms = philo->vars->cur_time - philo->vars->start_time;
	if (!philo->vars->philo_end)
		print_message(id, time_ms, " is thinking");
	philo->sleeping = 0;
	philo->thinking = 1;
	sem_post(philo->vars->sem_turn);
	return (1);
}

unsigned int	handle_state(t_philo *philo, t_vars *vars)
{
	unsigned int	next_timer;
	int				id;

	id = philo->id;
	next_timer = 1;
	if ((philo->sleeping && vars->cur_time - philo->prev_time
			>= vars->sleep_time)
		|| philo->thinking)
		next_timer = eat_state(philo, id);
	else if (philo->eating
		&& philo->vars->cur_time - philo->prev_mealtime
		>= philo->vars->eat_time)
		next_timer = sleep_state(philo, id);
	if (vars->die_time < next_timer)
		next_timer = vars->die_time;
	return (next_timer);
}

void	*philo_life(void *args)
{
	t_vars			*vars;
	t_philo			*philo;
	unsigned int	prev_time;
	unsigned int	next_timer;
	unsigned int	time;

	philo = (t_philo *)args;
	vars = philo->vars;
	prev_time = vars->start_time;
	next_timer = 0;
	philo->prev_time = prev_time;
	while (!vars->philo_end)
	{
		time = vars->cur_time - prev_time;
		if (time >= next_timer && !vars->philo_end)
		{
			prev_time = vars->cur_time;
			next_timer = handle_state(philo, vars);
		}
		usleep(300);
	}
	return (NULL);
}
