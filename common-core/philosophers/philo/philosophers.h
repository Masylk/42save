/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 04:47:55 by mtogbe            #+#    #+#             */
/*   Updated: 2021/11/22 19:02:20 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				alive;
	int				hasfork;
	int				sleeping;
	int				eating;
	int				thinking;
	int				goal;
	pthread_t		thread;
	int				last;
	int				fleft;
	int				fright;
	unsigned int	prev_time;
	unsigned int	prev_mealtime;
	struct s_philo	*previous;
	struct s_philo	*next;
	struct s_vars	*vars;
}		t_philo;

typedef struct s_vars
{
	int				nb;
	unsigned int	die_time;
	unsigned int	eat_time;
	unsigned int	cur_time;
	unsigned int	start_time;
	unsigned int	sleep_time;
	int				eat_goal;
	pthread_t		clock_thr;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*mutex_forks;
	int				philo_end;
	t_philo			*plist;
	int				*forks;
}		t_vars;

t_philo	*new_philo(int id);
t_philo	*get_philo(t_philo *list, int id);
int		think_state(t_philo *philo, int id);
int		sleep_state(t_philo *philo, int id);
int		eat_state(t_philo *philo, int id);
int		get_fork(t_vars *vars, int index);
int		get_forks(t_vars *vars, int fl, int fr, int id);
void	get_forks_back(t_vars *vars, int fl, int fr);
void	*ft_clock(void *args);
void	*philo_life(void *args);
void	add_end(t_philo **list, t_philo *elem);
void	add_start(t_philo **list, t_philo *elem);
void	free_philo(t_philo *list);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	print_timestamp(int ms);
void	get_time(unsigned int *t);
void	print_message(int nb, unsigned int time, char *msg, t_vars *vars);
int		choose_sleep(t_philo *philo);
int		ft_atoi(const char *nptr);
int		nblen(int nb);
int		ft_strlen(char *str);

#endif
