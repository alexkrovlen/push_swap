/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <pelease@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 01:19:47 by pelease           #+#    #+#             */
/*   Updated: 2020/06/18 19:50:19 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct		s_look
{
	int				a_cnt;
	int				b_cnt;
	int				cnt;
	int				flag;
	int				mid;
	int				max;
	int				next;
	t_list			*last;
	t_list			*head;
}					t_look;

typedef struct		s_stack
{
	int				val;
	int				order;
	int				is_sorted;
	int				flag;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				list_push(t_list **lst, char *data);
t_list				*list_create(char *data);
void				clear_list(t_list **lst);
void				swap(t_stack **a, t_stack **b, char c, t_look *st);
void				push(t_stack **a, t_stack **b, char c, t_look *st);
void				rotate(t_stack **a, t_stack **b, char c, t_look *st);
void				rev_rotate(t_stack **a, t_stack **b, char c, t_look *st);
int					set_stack(t_stack **a, int ac, char **av, int *cnt);
int					set_cmd_list(t_list **cmd);
void				print_stacks(t_stack *a, t_stack *b);
void				ft_quicksort(int *numbers, int left, int right);
void				parse_result(t_stack *a, t_stack *b);
void				array_sort(int *numbers, int left, int right);
void				continue_generate(t_stack **a,
						t_stack **b, t_look *st, int stop);
void				push_stack_a(t_stack **a,
						t_stack **b, t_look *st, int n);
void				push_stack_b(t_stack **a,
						t_stack **b, t_look *st, int flag);
int					stack_sorted(t_stack *stk);
void				move_up(t_stack **b, t_stack **a, t_look *st);
void				particular_sort(t_stack **a, t_stack **b, t_look *st);
void				parse_pushswap(t_look *st, t_stack **a, t_list *lst);
void				stack_sort(t_stack **a, t_stack **b, t_look *st, char c);

t_stack				*stack_create(int data);
void				stack_push(t_stack **stack, int data);
void				stack_add(t_stack **dest, t_stack *src);
t_stack				*stack_pop(t_stack **stack);
void				clear_stack(t_stack **stack);
void				print_stack(t_stack *stack, int rev);
void				stack_swap(t_stack **stack);
void				stack_rotate(t_stack **stack, int reverse);

#endif
