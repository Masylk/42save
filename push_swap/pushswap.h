/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:45:23 by mtogbe            #+#    #+#             */
/*   Updated: 2021/07/07 02:37:17 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				n;
	int				pos;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stacklist
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		nb_instr;
	int		*tab;
}				t_stacklist;

void		free_stlist(t_stacklist *list, char **arg);
int			small_sorts(t_stacklist *list, int size);
int			trick_sort(t_stacklist *list, int size);
int			trick_sort_plus(t_stacklist *list, int size);
int			two_sort(t_stacklist *list, int size);
int			rd_sort_stack(t_stacklist *list, int size);
int			sort_boxes(t_stacklist *list, int size, int max_bit, int ith);
int			check_ith_bit(t_stack *s, int i);
int			is_smallest(t_stack *s, int i);
int			is_biggest(t_stack *s, int i);
int			size_stack(t_stack *s);
int			pa(t_stack **a, t_stack **b);
int			sa(t_stack *a);
t_stack		*ra(t_stack *a);
t_stack		*rra(t_stack *a);
t_stack		*rrr(t_stack *a, t_stack *b);
int			pb(t_stack **b, t_stack **a);
int			sb(t_stack *b);
t_stack		*rb(t_stack *b);
t_stack		*rrb(t_stack *b);
int			init_stacks(t_stacklist *list, char **av);
void		set_order(t_stack *stack, int *tab);
void		postab_to_list(int *tab, t_stack *stack);
void		set_order_tab(int *tab, int size);
void		print_tab(int *tab, t_stack *stack);
void		print_stack(t_stack *stack);
int			stack_size(t_stack *list);
t_stack		*arr_to_stack(char **arr);
void		set_order(t_stack *stack, int *tab);
int			*list_to_tab(t_stack *list);
int			*poslist_to_tab(t_stack *list);
int			check_args(char **args, int *n);
int			swap(t_stack *stack);
int			push(t_stack **stack_s, t_stack **stack_d);
int			push2(t_stack *stack_s, t_stack *stack_d);
int			nb_is_sorted(int *stack, int i, int size);
int			stack_is_sorted(int *stack, int size);
t_stack		*rotate(t_stack *stack);
t_stack		*reverse_rotate(t_stack *stack);
t_stacklist	*double_swap(t_stacklist *l);
t_stacklist	double_rotate(t_stacklist l);
t_stacklist	double_rev_rotate(t_stacklist l);

#endif
