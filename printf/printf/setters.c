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

void	*set_flagsetters(int (***f)(t_flagmodes *, va_list))
{
	*f = malloc(sizeof(**f) * 5);
	if (!(*f))
		return (NULL);
	(*f)[0] = &set_left;
	(*f)[1] = &set_precision;
	(*f)[2] = &set_fill;
	(*f)[3] = &set_zero;
	return (*f);
}
