/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:07:49 by mtogbe            #+#    #+#             */
/*   Updated: 2021/11/22 20:08:30 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_fork(t_vars *vars, int index)
{
	if (vars->forks[index % vars->nb])
		return (vars->forks[index % vars->nb]);
	else
		return (0);
}

void	get_forks_back(t_vars *vars, int fl, int fr)
{
	pthread_mutex_unlock(&vars->mutex_forks[fl % vars->nb]);
	pthread_mutex_unlock(&vars->mutex_forks[fr % vars->nb]);
	vars->forks[fl % vars->nb] = 1;
	vars->forks[fr % vars->nb] = 1;
}

int	get_forks(t_vars *vars, int fl, int fr, int id)
{
	int	time_ms;

	pthread_mutex_lock(&vars->mutex);
	if ((get_fork(vars, fl) && get_fork(vars, fr)))
	{
		pthread_mutex_unlock(&vars->mutex);
		vars->forks[fl % vars->nb] = 0;
		vars->forks[fr % vars->nb] = 0;
		pthread_mutex_lock(&vars->mutex_forks[fl % vars->nb]);
		pthread_mutex_lock(&vars->mutex);
		time_ms = vars->cur_time - vars->start_time;
		print_message(id, time_ms, " has taken a fork", vars);
		pthread_mutex_unlock(&vars->mutex);
		if (vars->nb > 1)
		{
			pthread_mutex_lock(&vars->mutex_forks[fr % vars->nb]);
			pthread_mutex_lock(&vars->mutex);
			time_ms = vars->cur_time - vars->start_time;
			print_message(id, time_ms, " has taken a fork", vars);
			pthread_mutex_unlock(&vars->mutex);
			return (1);
		}
	}
	pthread_mutex_unlock(&vars->mutex);
	return (0);
}

void	print_message(int nb, unsigned int time, char *msg, t_vars *vars)
{
	if (vars->philo_end)
		return ;
	ft_putstr_fd("[", 1);
	ft_putnbr_fd(time, 1);
	ft_putstr_fd(" ms] : ", 1);
	ft_putstr_fd("Philosopher ", 1);
	ft_putnbr_fd(nb, 1);
	ft_putstr_fd(msg, 1);
	ft_putendl_fd("", 1);
}

int	choose_sleep(t_philo *philo)
{
	(void)philo;
	return (20);
}
