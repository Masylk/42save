/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 23:46:28 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/29 23:46:41 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	*check_meals(void *args)
{
	t_vars	*vars;
	int		count;

	count = 0;
	vars = (t_vars *)args;
	while (count != vars->eat_goal)
	{
		sem_wait(vars->sem_goal);
		count++;
	}
	sem_close(vars->sem_forks);
	sem_close(vars->sem_turn);
	sem_close(vars->sem_goal);
	sem_close(vars->sem_clock);
	free_philo(vars->plist);
	kill(0, SIGQUIT);
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
		sem_wait(vars->sem_clock);
		if (philo->vars->cur_time - philo->prev_mealtime >= vars->die_time)
		{
			print_message(philo->id, vars->cur_time - vars->start_time,
				" died");
			vars->philo_end = 1;
			kill(0, SIGQUIT);
			continue ;
		}
		sem_post(vars->sem_clock);
		usleep(10);
	}
	return (vars);
}
