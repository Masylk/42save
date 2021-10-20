/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 03:01:53 by mtogbe            #+#    #+#             */
/*   Updated: 2021/10/20 18:14:35 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philosophers(t_vars *vars, int nb)
{
	int		i;
	t_philo	*block;

	i = 1;
	while (i <= nb)
	{
		block = new_philo(i++);
		if (!block)
			return (-1);
		block->vars = vars;
		block->fleft = i % nb;
		if (nb != 1)
			block->fright = (i % nb) + 1;
		else
			block->fright = i % nb;
		block->prev_mealtime = vars->cur_time;
		add_end(&vars->plist, block);
		if (pthread_create(&block->thread,
				NULL, philo_life, (void *)block))
			return (-1);
	}
	return (1);
}

int	wait_thr(t_vars *vars)
{
	void	*ret;
	void	*cret;
	int		i;

	(void)i;
	i = 1;
	while (i <= vars->nb)
	{
		if (pthread_join(get_philo(vars->plist, i++)->thread, &ret))
			return (-1);
	}
	if (pthread_join(vars->clock_thr, &cret))
		return (-1);
	return (1);
}

int	init_args(t_vars *vars, char **av)
{
	vars->nb = ft_atoi(av[1]);
	if (nblen(vars->nb) != ft_strlen(av[1]) || vars->nb > 1024)
		return (0);
	vars->die_time = ft_atoi(av[2]);
	if (nblen(vars->die_time) != ft_strlen(av[2]))
		return (0);
	vars->eat_time = ft_atoi(av[3]);
	if (nblen(vars->eat_time) != ft_strlen(av[3]))
		return (0);
	vars->sleep_time = ft_atoi(av[4]);
	if (nblen(vars->sleep_time) != ft_strlen(av[4]))
		return (0);
	if (av[5])
	{
		vars->eat_goal = ft_atoi(av[5]);
		if (vars->eat_goal < 0)
			return (0);
		if (nblen(vars->eat_goal) != ft_strlen(av[5]))
			return (0);
	}
	else
		vars->eat_goal = -1;
	return (1);
}

int	init_vars(t_vars *vars, char **av)
{
	int	i;

	i = 0;
	vars->plist = NULL;
	pthread_mutex_init(&vars->mutex, NULL);
	if (!init_args(vars, av))
		return (0);
	vars->forks = malloc(sizeof(int) * (vars->nb));
	while (i < vars->nb)
		(vars->forks[i++]) = 1;
	get_time(&vars->start_time);
	vars->cur_time = vars->start_time;
	vars->philo_end = 0;
	if (pthread_create(&vars->clock_thr, NULL, ft_clock, (void *)vars))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac < 5 || ac > 6)
		return (printf("Wrong number of arguments"));
	if (init_vars(&vars, av) == 0)
		return (printf("Arguments bad format"));
	if (create_philosophers(&vars, vars.nb) < 0)
		return (0);
	if (wait_thr(&vars) < 0)
		return (0);
	free_philo(vars.plist);
	free(vars.forks);
	vars.forks = NULL;
	return (1);
}
