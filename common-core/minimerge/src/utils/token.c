/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:58:34 by flohrel           #+#    #+#             */
/*   Updated: 2021/05/20 18:36:05 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "calloc.h"

char	get_token_char(int type)
{
	if (type == TK_PIPE)
		return ('|');
	else if (type == TK_SEMI)
		return (';');
	else if (type == TK_QUOTE)
		return ('\'');
	else if (type == TK_DQUOTE)
		return ('\"');
	else if (type == TK_ESC)
		return ('\\');
	else if (type == TK_GREAT)
		return ('>');
	else if (type == TK_LESS)
		return ('<');
	else if (type == TK_SPACE)
		return (' ');
	else
		return (0);
}

int		get_token_type(char c)
{
	if (c == '|')
		return (TK_PIPE);
	else if (c == ';')
		return (TK_SEMI);
	else if (c == '\'')
		return (TK_QUOTE);
	else if (c == '\"')
		return (TK_DQUOTE);
	else if (c == '\\')
		return (TK_ESC);
	else if (c == '>')
		return (TK_GREAT);
	else if (c == '<')
		return (TK_LESS);
	else if (c == ' ')
		return (TK_SPACE);
	else
		return (TK_WORD);
}

void	del_token(void *content)
{
	t_token	*token;

	return ;
	token = (t_token *)content;
	if (token)
	{
		if (token->data)
			free(token->data);
		free(token);
	}
}

void	new_token(t_vars *vars, int type, int size)
{
	t_lexer	*lexer;
	t_token	*token;
	t_list	*lst;

	lexer = &vars->lexer;
	if (!(my_calloc(1, sizeof(*(token)), (void *)&(token))))
		clean_exit(vars, errno);
	token->type = type;
	token->data = NULL;
	lexer->cur_char = NULL;
	if (size)
	{
		if (!(my_calloc(size + 1, sizeof(*(token->data)), (void *)&(token->data))))
			clean_exit(vars, errno);
		lexer->cur_char = token->data;
	}
	lst = ft_lstnew(token);
	if (lst == NULL)
		clean_exit(vars, errno);
	ft_lstadd_back(&lexer->tk_list, lst);
}
