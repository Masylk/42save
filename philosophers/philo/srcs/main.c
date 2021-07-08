/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 03:01:53 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 04:49:16 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philosophers(t_vars *vars, int nb)
{
	int	i;
	t_philo	*block;

	i = 1;
	while (i <= nb)
	{
		block = new_philo(i++);
		if (!block)
			return (-1);
		add_end(&vars->plist, block);
	}
	debug_philo(vars->plist);
	i = 1;
	while (i <= nb)
	{
		if (pthread_create(&get_philo(vars->plist, i++)->thread,
				NULL, philo_life, (void *)vars))
			return (-1);
	}
	return (1);
}

int	wait_thr(t_vars *vars)
{
	void	*ret;
	int	i;

	i = 1;
	while (i <= vars->nb)
	{
		if (pthread_join(get_philo(vars->plist, i++)->thread, &ret))
			return (-1);
	}
	return (1);
}

void	init_vars(t_vars *vars, int nb)
{
	vars->plist = NULL;
	vars->nb = nb;
	vars->philo_end = 0;
}

int	main(int ac, char **av)
{
	t_vars	vars;
	(void)ac;
	(void)av;
	init_vars(&vars, 8);
	if (create_philosophers(&vars, vars.nb) < 0)
		return (0);
	if (wait_thr(&vars) < 0)
		return (0);
	ft_clock((void *)&vars);
	return (1);
}
