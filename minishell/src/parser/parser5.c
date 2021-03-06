/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 02:07:59 by flohrel           #+#    #+#             */
/*   Updated: 2021/05/20 18:28:05 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "calloc.h"

int		redirection(t_parser *parser, int type, t_cmd *data)
{
	t_token	*token;

	parser->cur_tk = parser->cur_tk->next;
	token = (t_token *)parser->cur_tk->content;
	if (token->type != 0)
		return (-1);
	token->type = type;
	ft_lstadd_back(&data->redir, parser->cur_tk);
	return (0);
}

void	argument(t_parser *parser, t_token *token, t_cmd *data)
{
	if (!data->path)
		data->path = token->data;
	else
		ft_lstadd_back(&data->arg, parser->cur_tk);
}

void	init_cmd_data(t_cmd *data)
{
	data->path = NULL;
	data->redir = NULL;
	data->arg = NULL;
}

t_ast	*cmd(t_vars *vars, t_parser *parser)
{
	t_ast	*node;
	t_cmd	*data;
	t_token	*token;

	if (!(my_calloc(1, sizeof(*(data)), (void *)&(data))))
		clean_exit(vars, errno);
	init_cmd_data(data);
	token = (t_token *)parser->cur_tk->content;
	while ((token->type == TK_WORD) || (token->type > TK_SEMI))
	{
		if ((token->type > TK_SEMI) &&
			(redirection(parser, token->type, data) == -1))
		{
			free_cmd_node(data);
			return (NULL);
		}
		else
			argument(parser, token, data);
		parser->cur_tk = parser->cur_tk->next;
		token = (t_token *)parser->cur_tk->content;
	}
	node = tree_new_node(vars, NODE_CMD, data);
	return (node);
}
