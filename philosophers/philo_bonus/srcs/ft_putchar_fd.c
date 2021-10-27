/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:46:00 by mtogbe            #+#    #+#             */
/*   Updated: 2021/10/27 16:02:49 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	set_child(int i, t_vars *vars)
{
	t_philo	*block;

	block = new_philo(i);
	if (!block)
		return (-1);
	block->vars = vars;
	block->prev_mealtime = vars->cur_time;
	vars->plist = block;
	if (pthread_create(&vars->clock_thr, NULL, ft_clock, (void *)vars))
		return (-1);
	if (pthread_create(&vars->death_thr, NULL, check_death, (void *)vars))
		return (-1);
	philo_life((void *) block);
	pthread_join(vars->clock_thr, NULL);
	pthread_join(vars->death_thr, NULL);
	return (0);
}
