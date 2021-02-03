#include "ft_printf.h"

int	conv_u(va_list *args, t_flagmodes *s, int *count)
{
	char    *str;
	int		len;

	str = ft_utoa((unsigned int)va_arg(*args, unsigned int));
    if (!str)
		return (-1);
	len = ft_strlen(str);
	print_conv_int(s, str, count, len);
    free(str);
	return (1);
}