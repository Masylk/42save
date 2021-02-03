#include "ft_printf.h"

int	conv_s(va_list *args, t_flagmodes *s, int *count)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)va_arg(*args, char *);
	if (!str)
		str = "(null)";
	if (s->precision)
		s->max = ft_min(ft_strlen(str), s->max);
	else
		s->max = ft_strlen(str);
	if (!(s->left) && s->min)
		*count += ft_putfill(s->min - s->max, s);
	while (str && str[i] && i < s->max && ++(*count))
		ft_putchar_fd(str[i++], 1);
	if (s->min && s->left)
		*count += ft_putfill(s->min - s->max, s);
	return (1);
}