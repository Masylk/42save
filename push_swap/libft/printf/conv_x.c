/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:32:15 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 02:31:11 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_x_lower(va_list *args, t_flagmodes *s, int *count)
{
	return (conv_x(args, s, count, "0123456789abcdef"));
}

int	conv_x_upper(va_list *args, t_flagmodes *s, int *count)
{
	return (conv_x(args, s, count, "0123456789ABCDEF"));
}

int	conv_x(va_list *args, t_flagmodes *s, int *count, char *base)
{
	char	*str;
	int		len;

	str = ft_utoa_base((unsigned int)va_arg(*args, unsigned int), base);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (s->max == 0 && str[0] == '0' && len == 1)
		print_conv_string(s, count, str);
	else
		print_conv_int(s, str, count, len);
	free(str);
	return (1);
}
