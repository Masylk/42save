/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:42:38 by flohrel           #+#    #+#             */
/*   Updated: 2021/05/20 18:40:35 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "calloc.h"

void	display_prompt(void)
{
	write(1, PROMPT, ft_strlen(PROMPT));
}

void	init_term(t_vars *vars)
{
	t_term	*termios;
	char	*term_type;

	termios = &vars->termios;
	if (tcgetattr(STDIN_FILENO, &termios->original) == -1)
		clean_exit(vars, errno);
	termios->current = termios->original;
	termios->current.c_lflag &= ~(ICANON);
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios->current))
		clean_exit(vars, errno);
	term_type = getenv("TERM");
	if (term_type == NULL || tgetent(NULL, term_type) <= 0)
		clean_exit(vars, 0);
}

void	ft_readline(t_vars *vars)
{
	char	buffer[BUFFER_SIZE];
	int		size;
	int		ret;
	int		i;

	size = 0;
	i = 0;
	ret = -1;
	while (ret)
	{
		size = read(0, &buffer[i], 4);
		ret = input_handle(vars, &buffer[i], size, &i);
	}
	if (!(my_calloc(i + 1, sizeof(*(vars->lexer.buffer)), (void *)&(vars->lexer.buffer))))
		clean_exit(vars, errno);
	ft_strlcpy(vars->lexer.buffer, buffer, i + 1);
}
