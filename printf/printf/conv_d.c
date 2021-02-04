#include "ft_printf.h"

int	conv_d(va_list *args, t_flagmodes *s, int *count)
{
	char	*str;
	int		len;

	str = ft_itoa((int)va_arg(*args, int));
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (str[0] == '-')
		len--;
	if (s->max == 0 && str[0] == '0' && len == 1)
		print_conv_string(args, s, count, str);
	else
		print_conv_int(s, str, count, len);
	free(str);
	return (1);
}
