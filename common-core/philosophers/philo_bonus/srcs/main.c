/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 03:01:53 by mtogbe            #+#    #+#             */
/*   Updated: 2021/10/27 16:02:31 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	limit_threads(t_vars *vars, int pid)
{
	if (pid)
	{
		if (pthread_create(&vars->goal_thr, NULL, check_meals,
				(void *)vars))
			return (0);
		if (pthread_create(&vars->end_thr, NULL, check_end,
				(void *)vars))
			return (0);
		pthread_join(vars->goal_thr, NULL);
		pthread_join(vars->end_thr, NULL);
	}
	return (1);
}

int	create_philosophers(t_vars *vars, int nb)
{
	int		i;
	int		pid;

	i = 1;
	while (i <= nb)
	{
		pid = fork();
		if (!pid)
		{
			if (set_child(i, vars) < 0)
				return (-1);
		}
		i++;
	}
	if (!limit_threads(vars, pid))
		return (-1);
	return (1);
}

int	init_args(t_vars *vars, char **av)
{
	vars->nb = ft_atoi(av[1]);
	if (!vars->nb || nblen(vars->nb) != ft_strlen(av[1]) || vars->nb > 1024)
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
	vars->plist = NULL;
	if (!init_args(vars, av))
		return (0);
	get_time(&vars->start_time);
	vars->cur_time = vars->start_time;
	vars->philo_end = 0;
	sem_unlink("/forks");
	sem_unlink("/turn");
	sem_unlink("/clock");
	sem_unlink("/goal");
	sem_unlink("/death");
	sem_unlink("/end");
	vars->sem_forks = sem_open("/forks", O_CREAT, 0644, vars->nb);
	vars->sem_turn = sem_open("/turn", O_CREAT, 0644, 1);
	vars->sem_goal = sem_open("/goal", O_CREAT, 0644, 0);
	vars->sem_death = sem_open("/death", O_CREAT, 0644, 0);
	vars->sem_end = sem_open("/end", O_CREAT, 0644, 0);
	vars->sem_clock = sem_open("/clock", O_CREAT, 0644, 1);
	return (1);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac < 5 || ac > 6)
		return (printf("Wrong number of arguments\n"));
	if (init_vars(&vars, av) == 0)
		return (printf("Arguments bad format\n"));
	if (create_philosophers(&vars, vars.nb) < 0)
		printf("Error\n");
	sem_close(vars.sem_forks);
	sem_close(vars.sem_goal);
	sem_close(vars.sem_clock);
	sem_close(vars.sem_turn);
	sem_close(vars.sem_death);
	sem_close(vars.sem_end);
	return (1);
}
