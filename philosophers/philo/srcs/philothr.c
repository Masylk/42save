/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philothr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:07:56 by mtogbe            #+#    #+#             */
/*   Updated: 2021/10/20 18:16:41 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eat_state(t_philo *philo, int id)
{
	int	time_ms;

	if (!philo->eating)
	{
		if (philo->sleeping && !philo->thinking)
				return (think_state(philo, philo->id));
		else if (!get_forks(philo->vars, philo->fleft, philo->fright, philo->id))
			return (1);
		pthread_mutex_lock(&philo->vars->mutex);
		time_ms = philo->vars->cur_time - philo->vars->start_time;
		print_message(id, time_ms, " is eating");
		philo->goal = philo->goal + 1;
		philo->eating = 1;
		philo->thinking = 0;
		philo->sleeping = 0;
		philo->prev_mealtime = philo->vars->cur_time;
		pthread_mutex_unlock(&philo->vars->mutex);
	}
	return (1);
}

int	sleep_state(t_philo *philo, int id)
{
	int	time_ms;

	if (!philo->sleeping)
	{
		pthread_mutex_lock(&philo->vars->mutex);
		philo->prev_time = philo->vars->cur_time;
		time_ms = philo->vars->cur_time - philo->vars->start_time;
		print_message(id, time_ms, " is sleeping");
		philo->sleeping = 1;
		philo->eating = 0;
		philo->thinking = 0;
		get_forks_back(philo->vars, philo->fleft, philo->fright);
		pthread_mutex_unlock(&philo->vars->mutex);
	}
	return (1);
}

int	think_state(t_philo *philo, int id)
{
	int	time_ms;

	if (philo->sleeping)
	{
		pthread_mutex_lock(&philo->vars->mutex);
		time_ms = philo->vars->cur_time - philo->vars->start_time;
		print_message(id, time_ms, " is thinking");
		philo->sleeping = 0;
		philo->thinking = 1;
		philo->eating = 0;
		pthread_mutex_unlock(&philo->vars->mutex);
	}
	return (1);
}

unsigned int	handle_state(t_philo *philo, t_vars *vars)
{
	unsigned int	next_timer;
	int				id;

	id = philo->id;
	next_timer = 1;
	if (!philo->eating)
	{
		if (philo->sleeping && philo->vars->cur_time - philo->prev_time >= vars->sleep_time)
			eat_state(philo, id);
		else if (!philo->sleeping)
			eat_state(philo, id);
	}
	else if (philo->vars->cur_time - philo->prev_mealtime >= vars->eat_time && philo->eating)
		sleep_state(philo, id);
	return (next_timer);
}

void	*philo_life(void *args)
{
	t_philo			*philo;
	unsigned int	prev_time;

	philo = (t_philo *)args;
	prev_time = philo->vars->start_time;
	philo->prev_time = prev_time;
	while (prev_time && !philo->vars->philo_end)
	{
		handle_state(philo, philo->vars);
		usleep(choose_sleep(philo));
	}
	return (NULL);
}
