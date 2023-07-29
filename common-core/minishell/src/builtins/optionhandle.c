
typedef struct	s_opt{
	int	optflag;
	char	**args;
}		t_opt;

//modifier strjoin avec le my_malloc
char	*check_options(char *str, char *opt, char *flags)
{
	int	i;
	char	*result;

	i = 0;
	while (arg[pos][i])
	{
		if (ft_ischarset(str[i], flags))
		{
			i++;
			continue ;
		}
		if (!(ft_ischarset(str[i], opt)))
			return (NULL);
		result = ft_strjoin(flags, str[i++]);
	}
	return (result);
}

t_opt	optionhandler(char **args, char *opt)
{
	t_opt	options;
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (args[i] && ft_startwith(args[i], '-'))
	{
		options.optflag = check_options(args[i++], opt);
	}
	if (!(my_calloc(ft_tablen(args + i), sizeof(char *),
					(void *)&(options.arg))))
		return (NULL);
	while (args[i])
		options.args[j++] = args[i++];
	return (options);
}
