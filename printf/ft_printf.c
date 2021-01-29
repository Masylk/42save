/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:05:39 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/28 17:00:16 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_flags(char c, t_flagmodes *flagmodes, char *str, va_list arg)
{
	char	*flags;
	int		fill;

	flags = "-.*";
	if (ft_getpos(c, flags) >= 0)
	{
		if (c == '*')
			fill = (int)va_arg(arg, int);
		if ((c == '-' && !(flagmodes->left) || fill < 0) && !(flagmodes->precision))
			return (set_flag(&(flagmodes->left)));
		else if (c == '.' && !(flagmodes->precision))
			return (set_flag(&(flagmodes->precision)));
		return (-1);
	}
	else if (ft_isdigit(c))
	{
		if (flagmodes->precision && flagmodes->max < 0)
			return (set_size(&(flagmodes->max), str));
		else if (!(flagmodes->min))
			return (set_size(&(flagmodes->min), str));
		return (-1);
	}
	return (0);
}

int	get_format(char *str, t_flagmodes *flagmodes, va_list args)
{
	char		*formats;
	int			i;
	int			format;
	int			flag;

	formats = "cspdiuxX";
	i = 1;
	if (!str)
		return (i);
	while (str[i])
	{
		flag = get_flags(str[i], flagmodes, str + i, args); 
		if (flag < 0)
			break ;
		else if (flag > 0)
		{
		//	printf("left : %d\nprecision : %d\nmin : %d\nmax : %d\n", flagmodes->left, flagmodes->precision, flagmodes->min, flagmodes->max);
			i += flag;
		}
		else
		{
			format = ft_getpos(str[i], "-");
			if (format < 0)
				break ;
			i++;
		}
	}
	return (i);
}

int	set_flagmodes(t_flagmodes *flagmodes)
{
	flagmodes->left = 0;
	flagmodes->precision = 0;
	flagmodes->min = 0;
	flagmodes->max = -1;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		args;
	t_flagmodes	flagmodes;

	va_start(args, str);
	i = 0;
	set_flagmodes(&flagmodes);
	//printf("left : %d\nprecision : %d\nmin : %d\nmax : %d\n", flagmodes.left, flagmodes.precision, flagmodes.min, flagmodes.max);
	if (!str)
		return (i);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += get_format((char*)str + i, &flagmodes, args);
		}
		ft_putchar_fd(str[i++], 1);
	}
	return (i);
}

int	main(void)
{
	char	str[] = "ouuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuui";

	ft_printf("allo%-10.i%ca\n");
	printf("a%-*.2skb", -18, str);
}
