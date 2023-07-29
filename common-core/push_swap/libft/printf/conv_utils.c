/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:32:10 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 02:31:16 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	print_conv_int(t_flagmodes *s, char *str, int *count, int len)
{
	int	i;

	i = 0;
	if (s->precision || s->left)
		s->zero = 0;
	if (str[0] == '-' && (s->zero) && ++(*count))
		ft_putchar_fd(str[i++], 1);
	s->max = ft_max(len, s->max);
	if (str[0] == '-')
		s->min -= 1;
	if (!(s->left) && s->min)
		*count += ft_putfill(s->min - s->max, s);
	if (s->precision)
	{
		s->zero = 1;
		if (str[0] == '-' && ++(*count))
			ft_putchar_fd(str[i++], 1);
		*count += ft_putfill(s->max - len, s);
		s->zero = 0;
	}
	while (str && str[i] && ++(*count))
		ft_putchar_fd(str[i++], 1);
	if (s->min && s->left)
		*count += ft_putfill(s->min - s->max, s);
}

int	ft_putfill(int n, t_flagmodes *s)
{
	char	fill;
	int		i;

	i = 0;
	fill = ' ';
	if (s->zero)
		fill = '0';
	while (n-- > 0 && ++i)
		ft_putchar_fd(fill, 1);
	return (i);
}
