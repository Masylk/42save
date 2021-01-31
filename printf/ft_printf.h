/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:34:27 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/31 14:54:48 by mtogbe           ###   ########.fr       */
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
	int	fill;
	int	min;
	int	max;
	int	zero;
}				t_flagmodes;

int	ft_getpos(char c, char *str);
int	ft_nblen(int nb);
int	set_flag(int *flag);
int	set_size(int *width, char *str);
int	set_zero(t_flagmodes *s, va_list arg);
int	set_precision(t_flagmodes *s, va_list arg);
int	set_fill(t_flagmodes *s, va_list arg);
int	set_left(t_flagmodes *s, va_list arg);
int	(**set_flagsetters(void))(t_flagmodes *, va_list);

#endif
