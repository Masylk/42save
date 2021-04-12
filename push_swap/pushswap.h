/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:45:23 by mtogbe            #+#    #+#             */
/*   Updated: 2021/04/01 16:36:53 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"

typedef struct	s_stack
{
	int		n;
	struct	s_stack	*next;
}				t_stack;

typedef struct	s_stacklist
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_stacklist;

int		check_args(char **args, int *n);
int		swap(t_stack *stack);
int		push(t_stack *stack_s, t_stack *stack_d);
t_stack	*rotate(t_stack *stack);
t_stack	*reverse_rotate(t_stack *stack);
t_stacklist	*double_swap(t_stacklist *l);
t_stacklist	double_rotate(t_stacklist l);
t_stacklist	double_rev_rotate(t_stacklist l);

#endif
