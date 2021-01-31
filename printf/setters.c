/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:53:07 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/31 16:52:27 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_precision(t_flagmodes *s, va_list arg)
{
	(void)arg;
	if (!(s->precision))
	{
		s->zero = 0;
		s->max = 0;
		return (set_flag(&(s->precision)));
	}
	return (-1);
}

int	set_left(t_flagmodes *s, va_list arg)
{
	(void)arg;
	if (!(s->left) && !(s->precision))
			return (set_flag(&(s->left)));
	return (-1);
}

int	set_fill(t_flagmodes *s, va_list arg)
{
	s->fill = (int)va_arg(arg, int);
	if (!(s->precision) && !(s->min))
	{
		if (s->fill <0)
		{
			s->left = 1;
			s->min = -(s->fill);
		}
		else
			s->min = s->fill;
		return (1);
	}
	else if (s->precision)
	{
		if (s->fill < 0)
		{
			s->precision = 0;
			s->max = -(s->fill);
		}
		else
			s->max = s->fill;
		return (1);

	}
	return (-1);
}

int	set_zero(t_flagmodes *s, va_list arg)
{
	(void)arg;
	if (!(s->left) && !(s->precision))
		s->zero = 1;
	return (1);
}

int	(**set_flagsetters(void))(t_flagmodes *, va_list)
{
	int			(**flagsetters)(t_flagmodes *s, va_list a);

	flagsetters = malloc(sizeof(*flagsetters) * 4);
	if (!flagsetters)
		return (NULL);
	flagsetters[0] = &set_left;
	flagsetters[1] = &set_precision;
	flagsetters[2] = &set_fill;
	flagsetters[3] = &set_zero;
	return (flagsetters);
}
