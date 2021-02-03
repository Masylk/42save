#include "ft_printf.h"

int	conv_d(va_list *args, t_flagmodes *s, int *count)
{
	char    *str;
	int		len;

	str = ft_itoa((int)va_arg(*args, int));
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (str[0] == '-')
		len--;
	print_conv_int(s, str, count, len);
    free(str);
	return (1);
}