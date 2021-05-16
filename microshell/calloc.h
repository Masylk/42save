/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:34:47 by mtogbe            #+#    #+#             */
/*   Updated: 2021/05/16 17:21:37 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALLOC_H
# define CALLOC_H

# include <stdlib.h>
# include <stdio.h>

typedef struct	s_cal
{
	void			*content;
	struct s_cal	*next;
}				t_cal;

t_cal	**my_calloc(size_t nmemb, size_t size, void **ptr);
void	free_all(t_cal **lst);
void	free_part_end(void *ptr, t_cal **list);
void	free_part_start(void *ptr, t_cal **list);
void	free_part(void *ptr, t_cal **lst);
void	print_lst(t_cal *lst);
#endif
