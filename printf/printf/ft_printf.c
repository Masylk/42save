/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:05:39 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/03 17:08:19 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_flags(t_flagmodes *flagmodes, char *str, va_list *arg)
{
	char	*flags;
	int		i;
	int			(**flagsetters)(t_flagmodes *s, va_list *a);

	if (!set_flagsetters(&flagsetters))
		return (-1);
	flags = "-.*0";
	i = ft_getpos(str[0], flags);
	if (i >= 0)
		return ((*flagsetters[i])(flagmodes, arg));
	else if (ft_isdigit(str[0]))
	{
		if (flagmodes->precision && flagmodes->max <= 0)
			return (set_size(&(flagmodes->max), str));
		else if (!(flagmodes->min))
			return (set_size(&(flagmodes->min), str));
		return (-1);
	}
	free(flagsetters);
	return (0);
}

void	*set_converters(int (***f)(va_list *, t_flagmodes *, int *))
{
	*f = malloc(sizeof(**f) * 8);
	if (!(*f))
		return (NULL);
	(*f)[0] = &conv_c;
	(*f)[1] = &conv_s;
	(*f)[2] = &conv_p;
	(*f)[3] = &conv_d;
	(*f)[4] = &conv_d;
	(*f)[5] = &conv_u;
	(*f)[6] = &conv_x_lower;
	(*f)[7] = &conv_x_upper;
	return (*f);
}

int	get_format(char *str, t_flagmodes *flagmodes, va_list *args, int *count)
{
	int			i;
	int			format;
	int			flag;
	int			(**converters)(va_list *a, t_flagmodes *s, int *c);

	if (!set_converters(&converters))
		return (-1);
	i = 1;
	format = -1;
	flag = 1;
	while (str[i] && flag >= 0 && format < 0 && !(flag == 0 && format < 0))
	{
		flag = get_flags(flagmodes, str + i, args); 
		if (flag > 0)
			i += flag;
		else if (flag == 0)
			format = ft_getpos(str[i], "cspdiuxX");
		if (flag >= 0 && format >= 0 && i++)
			(*converters[format])(args, flagmodes, count);
	}
	if (str[i] && (format < 0 || flag < 0))
		print_conv_char(str[i++], flagmodes, count);
	free(converters);
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
	int			ret;

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
			ret = get_format((char*)str + i, &flagmodes, &args, &count);
			if (ret < 0)
				return (-1);
			i += ret;
		}
		else if (++count)
			ft_putchar_fd(str[i++], 1);
	}
	return (count);
}

/*int	main(void)
{
	//char	*str = "ou\\0uuui";
//	char	*str2 = "oudaz\\0uuui";
	int		ret;

	ret = ft_printf("1 : %05%\n");
	printf("ret 1 : %d\n", ret);
	ret = printf("2 : %05%\n");
	printf("ret 2 : %d\n", ret);
	ret = ft_printf("1 : %-05%\n");
	printf("ret 1 : %d\n", ret);
	ret = printf("2 : %-05%\n");
	printf("ret 2 : %d\n", ret);
	ret = ft_printf("1 : %5%\n");
	printf("ret 1 : %d\n", ret);
	ret = printf("2 : %5%\n");
	printf("ret 2 : %d\n", ret);
	ret = ft_printf("1 : %-5%\n");
	printf("ret 1 : %d\n", ret);
	ret = printf("2 : %-5%\n");
	printf("ret 2 : %d\n", ret);
}*/
