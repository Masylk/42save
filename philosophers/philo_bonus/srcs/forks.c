/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:50:16 by mtogbe            #+#    #+#             */
/*   Updated: 2021/10/21 17:50:18 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(int nb, unsigned int time, char *msg)
{
	ft_putstr_fd("[", 1);
	ft_putnbr_fd(time, 1);
	ft_putstr_fd(" ms] : ", 1);
	ft_putstr_fd("Philosopher ", 1);
	ft_putnbr_fd(nb, 1);
	ft_putstr_fd(msg, 1);
	ft_putendl_fd("", 1);
}

void	print_timestamp(int ms)
{
	ft_putstr_fd("[", 1);
	ft_putnbr_fd(ms, 1);
	ft_putendl_fd(" ms]", 1);
}

int	get_fork(t_vars *vars, int index)
{
	return (vars->forks[index % vars->nb]);
}

void	get_forks_back(t_vars *vars, int fl, int fr)
{
	vars->forks[fl % vars->nb] = 1;
	vars->forks[fr % vars->nb] = 1;
}

int	get_forks(t_vars *vars, int fl, int fr)
{
	if (get_fork(vars, fl) && get_fork(vars, fr))
	{
		vars->forks[fl % vars->nb] = 0;
		vars->forks[fr % vars->nb] = 0;
		return (1);
	}
	return (0);
}
