/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:34:27 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/27 12:07:49 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdio.h>

typedef	struct	s_flagmodes
{
	int	precision;
	int	left;
	int	min;
	int	max;
}				t_flagmodes;

int	ft_getpos(char c, char *str);
int	ft_nblen(int nb);
int	set_flag(int *flag);
int	set_size(int *width, char *str);

#endif
