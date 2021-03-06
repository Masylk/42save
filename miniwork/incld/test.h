/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:19:08 by flohrel           #+#    #+#             */
/*   Updated: 2021/05/27 07:25:45 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include "libft.h"
# include "data.h"

void	display_token_list(t_lexer *lexer);
void	print_lst(t_list *lst);
void	tree_display(t_ast *node, int level, int is_right);

#endif
