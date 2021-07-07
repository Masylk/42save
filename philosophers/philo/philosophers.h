/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 04:47:55 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 04:48:51 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int		id;
	int		alive;
	int		hasfork;
	int		sleeping;
	int		eating;
	int		thinking;
	pthread_t	thread;
	int		last;
	struct s_philo	*previous;
	struct s_philo	*next;
}		t_philo;

typedef struct s_vars
{
	int	nb;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	eat_goal;
	t_philo	*plist;
}		t_vars;

t_philo	*new_philo(int id);
t_philo	*get_philo(t_philo *list, int id);
void	*philo_life(void *args);
void	add_end(t_philo **list, t_philo *elem);
void	add_start(t_philo **list, t_philo *elem);
void	debug_philo(t_philo *list);

#endif
