/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:34:27 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/04 16:16:38 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

typedef	struct	s_flagmodes
{
	int	precision;
	int	left;
	int	fill;
	int	min;
	int	max;
	int	zero;
}				t_flagmodes;

int				ft_getpos(char c, char *str);
int				ft_nblen(int nb);
int				set_flag(int *flag);
int				set_size(int *width, char *str);
int				set_zero(t_flagmodes *s, va_list *arg);
int				set_precision(t_flagmodes *s, va_list *arg);
int				set_fill(t_flagmodes *s, va_list *arg);
int				set_left(t_flagmodes *s, va_list *arg);
void			*set_flagsetters(int (***f)(t_flagmodes *, va_list *));
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				ft_putfill(int n, t_flagmodes *s);
void			print_conv_int(t_flagmodes *s, char *str, int *count, int len);
void			print_conv_string(t_flagmodes *s, int *count, char *str);
void			print_conv_char(char c, t_flagmodes *s, int *count);
int				conv_s(va_list *args, t_flagmodes *s, int *count);
int				conv_c(va_list *args, t_flagmodes *s, int *count);
int				conv_d(va_list *args, t_flagmodes *s, int *count);
int				conv_x(va_list *args, t_flagmodes *s, int *count, char *base);
int				conv_x_upper(va_list *args, t_flagmodes *s, int *count);
int				conv_x_lower(va_list *args, t_flagmodes *s, int *count);
int				conv_u(va_list *args, t_flagmodes *s, int *count);
int				conv_p(va_list *args, t_flagmodes *s, int *count);

#endif
