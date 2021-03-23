/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:31:55 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/04 15:32:20 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_conv_char(char c, t_flagmodes *s, int *count)
{
	if (s->precision)
		s->max = ft_min(1, s->max);
	else
		s->max = 1;
	if (!(s->left) && s->min)
		*count += ft_putfill(s->min - s->max, s);
	if (s->max > 0 && ++(*count))
		ft_putchar_fd(c, 1);
	if (s->min && s->left)
		*count += ft_putfill(s->min - s->max, s);
}

int		conv_c(va_list *args, t_flagmodes *s, int *count)
{
	char	c;

	c = (char)va_arg(*args, int);
	print_conv_char(c, s, count);
	return (1);
}
