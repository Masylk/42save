/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 23:30:58 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/29 23:35:19 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_timestamp(int ms)
{
	ft_putstr_fd("[", 1);
	ft_putnbr_fd(ms, 1);
	ft_putendl_fd(" ms]", 1);
}

int	wait_thr(t_vars *vars)
{
	void	*cret;

	if (pthread_join(vars->clock_thr, &cret))
		return (-1);
	return (1);
}

void	get_time(unsigned int *t)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	*t = ((unsigned int)tm.tv_sec * 1000) + ((unsigned int)tm.tv_usec / 1000);
}

int	check_meals(t_vars *vars)
{
	t_philo	*tmp;

	tmp = vars->plist;
	while (tmp && !tmp->last)
	{
		if (tmp->goal != vars->eat_goal)
			return (0);
		tmp = tmp->next;
	}
	vars->philo_end = 1;
	return (1);
}

void	*ft_clock(void *args)
{
	t_vars		*vars;

	vars = (t_vars *)args;
	while (!vars->philo_end)
	{
		pthread_mutex_lock(&vars->mutex);
		get_time(&vars->cur_time);
		check_meals(vars);
		pthread_mutex_unlock(&vars->mutex);
		usleep(1000);
	}
	return (vars);
}
