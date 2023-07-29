/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:34:47 by mtogbe            #+#    #+#             */
/*   Updated: 2021/05/20 17:11:30 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALLOC_H
# define CALLOC_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_cal
{
	void			*content;
	struct s_cal	*next;
}				t_cal;

t_cal	**my_calloc(size_t nmemb, size_t size, void **ptr);
void	free_all(t_cal **lst);
t_cal	*free_part(void *ptr, t_cal *lst);
void	print_lst(t_cal *lst);
#endif
