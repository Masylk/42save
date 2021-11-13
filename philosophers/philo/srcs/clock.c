/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:07:25 by mtogbe            #+#    #+#             */
/*   Updated: 2021/10/20 17:07:43 by mtogbe           ###   ########.fr       */
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
	while (tmp && !tmp->last)
	{
		if (tmp->goal != vars->eat_goal)
			return (0);
		tmp = tmp->next;
	}
	if (tmp && !tmp->last)
	{
		if (tmp->goal != vars->eat_goal)
			return (0);
	}
	pthread_mutex_unlock(&vars->turn);
	vars->philo_end = 1;
	return (1);
}

void	*ft_clock(void *args)
{
	t_vars		*vars;
	int		nb;

	vars = (t_vars *)args;
	while (!vars->philo_end)
	{
		nb = 0;
		pthread_mutex_lock(&vars->mutex);
		get_time(&vars->cur_time);
		check_meals(vars);
		while (nb < vars->nb)
		{
			if (vars->plist->vars->cur_time - vars->plist->prev_mealtime >= vars->die_time + 1)
			{
				print_message(vars->plist->id, vars->cur_time - vars->start_time,
						" died");
				vars->philo_end = 1;
				pthread_mutex_unlock(&vars->turn);
			}
			vars->plist = vars->plist->next;
			nb++;
		}
		pthread_mutex_unlock(&vars->mutex);
		usleep(10);
	}
	return (vars);
}
