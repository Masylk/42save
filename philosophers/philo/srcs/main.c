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

void	print_config(t_vars *vars)
{
	printf("nb philo : %d\n", vars->nb);
	printf("time before death : %d\n", vars->die_time);
	printf("time to eat : %d\n", vars->eat_time);
	printf("time sleeping: %d\n", vars->sleep_time);
	printf("eat goal : %d\n", vars->eat_goal);
}

int	init_vars(t_vars *vars, char **av)
{
	vars->plist = NULL;
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
		if (nblen(vars->eat_goal) != ft_strlen(av[5]))
			return (0);
	}
	else
		vars->eat_goal = -1;
	vars->philo_end = 0;
	print_config(vars);
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
	ft_clock((void *)&vars);
	return (1);
}
