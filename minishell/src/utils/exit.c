/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:58:07 by flohrel           #+#    #+#             */
/*   Updated: 2021/05/20 18:31:09 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "calloc.h"

void	del_arg(void *content)
{
	char	*arg;

	return ;
	arg = (char *)content;
	if (arg)
		free(arg);
}

void	free_cmd_node(t_cmd *data)
{
	return ;
	if (data->path)
		free(data->path);
	ft_lstclear(&data->redir, del_token);
	ft_lstclear(&data->arg, del_arg);
}

void	free_vars(t_lexer *lexer, t_parser *parser)
{
	return ;
	ft_lstclear(&(lexer->tk_list), del_token);
	if (lexer->buffer)
		free(lexer->buffer);
	if (parser->exec_tree)
		tree_delete_node(parser->exec_tree);
}

void	clean_exit(t_vars *vars, int status)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &vars->termios.original);
	//free_vars(&vars->lexer, &vars->parser);
	free_all(my_calloc(0, 0, NULL));
	if (errno)
		printf("%s\n", strerror(errno));
	exit(128 + status);
}
