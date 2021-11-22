/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:07:25 by mtogbe            #+#    #+#             */
/*   Updated: 2021/11/22 20:13:28 by mtogbe           ###   ########.fr       */
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

int	check_meals(t_vars *vars)
{
	t_philo	*tmp;

	tmp = vars->plist;
	if (vars->eat_goal < 0)
		return (0);
	while (tmp && !tmp->last)
	{
		if (tmp->goal < vars->eat_goal)
			return (0);
		tmp = tmp->next;
	}
	if (tmp && !tmp->last)
	{
		if (tmp->goal < vars->eat_goal)
			return (0);
	}
	vars->philo_end = 1;
	return (1);
}

int	check_death(t_vars *vars)
{
	if (vars->plist->vars->cur_time
		- vars->plist->prev_mealtime >= vars->die_time + 1)
	{
		print_message(vars->plist->id, vars->cur_time - vars->start_time,
			" died", vars);
		return (1);
	}
	return (0);
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
		while (vars->plist)
		{
			vars->philo_end = check_death(vars);
			if (vars->plist->last)
				break ;
			vars->plist = vars->plist->next;
		}
		ft_putnbr_fd(vars->philo_end, 1);
		if (vars->plist && vars->plist->next)
			vars->plist = vars->plist->next;
		pthread_mutex_unlock(&vars->mutex);
		usleep(5);
	}
	return (vars);
}
