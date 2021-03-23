/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:32:04 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/04 16:57:19 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_conv_string(t_flagmodes *s, int *count, char *str)
{
	int	i;

	i = 0;
	if (s->precision)
	{
		s->zero = 0;
		s->max = ft_min(ft_strlen(str), s->max);
	}
	else
		s->max = ft_strlen(str);
	if (!(s->left) && s->min)
		*count += ft_putfill(s->min - s->max, s);
	while (str && str[i] && i < s->max && ++(*count))
		ft_putchar_fd(str[i++], 1);
	if (s->min && s->left)
		*count += ft_putfill(s->min - s->max, s);
}

int		conv_s(va_list *args, t_flagmodes *s, int *count)
{
	char	*str;

	str = (char *)va_arg(*args, char *);
	if (!str)
		str = "(null)";
	print_conv_string(s, count, str);
	return (1);
}
