#include "ft_printf.h"

char    *set_prefix(char *str)
{
    char    *tmp;

    tmp = str;
    str = ft_strjoin("00", tmp);
    free(tmp);
    if (!str)
        return (NULL);
    return (str);
}

int     conv_p(va_list *args, t_flagmodes *s, int *count)
{
	char	*str;
    int     len;

	str = ft_ultoa_base((unsigned long)va_arg(*args, void *), "0123456789ABCDEF");
	if (!str)
		return (-1);
    str = set_prefix(str);
    if (!str)
        return (-1);
	len = ft_strlen(str);
	print_conv_int(s, str, count, len);
    free(str);
	return (1);
}