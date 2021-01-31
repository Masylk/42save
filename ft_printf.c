#include <stdarg.h>
//#include "libft.h"
#include <stdio.h>

typedef struct s_flagmodes
{
    int precision;
    int left;
    int min;
    int max;
}              t_flagmodes;

int ft_getpos(char c, char *str)
{
    int i;

    i =  0;
    while (str && str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

int set_flag(int *flag)
{
    if (!(*flag))
        *flag = 1;
    else
        return (-1);
    return (1);
}

int ft_nblen(int nb)
{
    int i;

    i = 1;
    while (nb / 10)
    {
        nb /= 10;
        i++;
    }
    return (i);
}

int set_size(int *width, char *str)
{
    int i;

    i = 0;
    *width = ft_atoi(str);
    return (ft_nblen(*width));
}

int get_flags(char c, t_flagmodes *flagmodes, char *str)
{
    char        *flags;

    flags = "-.";
    if (ft_getpos(c, flags))
    {
        if (c == '-' && !(flagmodes->left) && !(flagmodes->precision))
            return (set_flag(&(flagmodes->left)));
        else if (c == '.' && !(flagmodes->precision))
            return (set_flag(&(flagmodes->precision)));
        return (-1);
    }
    else if (ft_isdigit(c))
    {
        if (flagmodes->precision && !(flagmodes->max))
            return (set_size(&(flagmodes->max), str));
        else if (!(flagmodes->min))
            return (set_size(&(flagmodes->max), str));
        return (-1);
    }
    return (0);
}

//todo : créer .h, vérifier que les données sont bien intégrées dans la structure
int get_format(char *str, int *min_width, int *max_width)
{
    t_flagmodes flagmodes;
    char        *formats;
    int         flag;
    int         i;

    formats = "cspdiuxX";
    i = 1;
    if (!str)
        return (i);
    while (str[i])
    {
        if (get_flags(str[i], &flagmodes, str + i) < 0)
            break ;
        i++;
    }
    //ft_putchar_fd(str[i], 1);
    return (i);
}

int ft_printf(const char *str, ...)
{
    int     i;
    int     min_width;
    int     max_width;

    i = 0;
    min_width = -1;
    max_width = -1;
    if (!str)
        return (i);
    while (str[i])
    {
        if (str[i] == '%')
        {
            i += get_format((char*)str + i, &min_width, &max_width);
        }
        //else
        //    ft_putchar_fd(str[i++]);
    }
    return (i);
}

int main()
{
    char    str[] = "ouuuuuui";
    //. : forcément suivi d'un nombre ou *
    //. : pas d'autres flags après
    printf("a%-.10skb", str, str);
}
