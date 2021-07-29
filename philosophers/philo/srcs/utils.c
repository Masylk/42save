/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 23:39:35 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/29 23:41:41 by mtogbe           ###   ########.fr       */
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

int	choose_sleep(t_philo *philo)
{
	if (philo->eating)
		return (philo->vars->eat_time * 1000);
	return (10);
}
