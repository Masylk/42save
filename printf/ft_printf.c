/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:05:39 by mtogbe            #+#    #+#             */
/*   Updated: 2021/01/31 17:02:34 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_flags(t_flagmodes *flagmodes, char *str, va_list arg, int (**f)(t_flagmodes *, va_list))
{
	char	*flags;
	int		i;

	flags = "-.*0";
	i = ft_getpos(str[0], flags);
	if (i >= 0)
		return ((*f[i])(flagmodes, arg));
	else if (ft_isdigit(str[0]))
	{
		if (flagmodes->precision && flagmodes->max < 0)
			return (set_size(&(flagmodes->max), str));
		else if (!(flagmodes->min))
			return (set_size(&(flagmodes->min), str));
		return (-1);
	}
	return (0);
}

int	conv_s(va_list args, t_flagmodes *s, int *count)
{
	char	*str;
	int		i;

	(void)s;
	(void)count;
	i = 0;
	str = (char *)va_arg(args, char *);
	while (str[i])
		ft_putchar_fd(str[i++], 1);
	return (1);
}

void	*set_converters(int (***f)(va_list, t_flagmodes *, int *))
{
	//int			(**converters)(va_list a, t_flagmodes *s, int o);

	*f = malloc(sizeof(**f) * 8);
	if (!(*f))
		return (NULL);
	(*f[1]) = &conv_s;
	return (*f);
}

int	get_format(char *str, t_flagmodes *flagmodes, va_list args, int *count)
{
	int			i;
	int			format;
	int			flag;
	int			(**flagsetters)(t_flagmodes *s, va_list a);
	int			(**converters)(va_list a, t_flagmodes *s, int *c);

	i = 1;
	flagsetters = set_flagsetters();
	set_converters(&converters);
	while (str[i] && flag >= 0)
	{
		flag = get_flags(flagmodes, str + i, args, flagsetters); 
		if (flag > 0)
			i += flag;
		else
		{
			format = ft_getpos(str[i], "cspdiuxX");
			if (format >= 0)
				(*converters[i])(args, flagmodes, count);
			break ;
		}
	}
	return (i);
}

int	set_flagmodes(t_flagmodes *flagmodes)
{
	flagmodes->left = 0;
	flagmodes->precision = 0;
	flagmodes->fill = 0;
	flagmodes->min = 0;
	flagmodes->max = -1;
	flagmodes->zero = 0;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			count;
	va_list		args;
	t_flagmodes	flagmodes;

	i = 0;
	count = 0;
	va_start(args, str);
	if (!str)
		return (i);
	while (str[i])
	{
		if (str[i] == '%')
		{
			set_flagmodes(&flagmodes);
			i += get_format((char*)str + i, &flagmodes, args, &count);
		}
		else
		{
			count++;
			ft_putchar_fd(str[i++], 1);
		}
	}
	return (count);
}

int	main(void)
{
	char	str[] = "ouuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuui";

	(void)str;
	ft_printf("allo%s%%ca\n", str);
	printf("a%100.skb", str);
}
