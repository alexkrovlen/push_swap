/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:53:13 by fjessi            #+#    #+#             */
/*   Updated: 2020/02/26 14:53:15 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./ft_printf/include/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

typedef struct		s_stack
{
	int					value;
    int					index;
	struct s_stack		*next;
	struct s_stack		*prev;
}					t_stack;

typedef struct		s_head
{
	t_stack				*stack;
	int16_t				size;
}					t_head;

void		print_stack_index(t_head *a);
void		print_stack(t_head *a);
void		print_two_stack(t_head *a, t_head *b);
int         *validation(int ac, char **av);
long int	ft_atoi_new(char *str);
void        exit_error(void);
int			*check_repeat(char **av);
t_head		*making_stack(int ac, char **av);
int			count_number(char **av);
int			*sort_massiv(int *stack, int start, int end);
void		get_index(t_head *head_a, int *stack, int count);
void		instruction(t_head *stack_a, t_head *stack_b);
void		ss_instruction(t_head *head_a, t_head *head_b);
void		sa_sb_instruction(t_head *head_a);
void		pa_pb_instruction(t_head *head_a, t_head *head_b);
void		ra_rb_instruction(t_head *head_a);
void		rr_instruction(t_head *head_a, t_head *head_b);
void		rra_rrb_instruction(t_head *head_a);
void		rrr_instruction(t_head *head_a, t_head *head_b);
int			check_sort(t_head *head_a, t_head *head_b);
void		simple_alg(t_head *head_a);
void		no_simple_alg(t_head *head_a);
void		middle_alg(t_head *head_a, int part);
void		advanced_alg(t_head *head_a, int part);
void		one_part(t_head *head_a, t_head *head_b, int start, int end);
int			find_max_b(t_head *head);
int			find_min_b(t_stack *head);
void		push_to_rrr_b(t_head *head_a, t_head *head_b, int count_step);
void		push_to_rr_b(t_head *head_a, t_head *head_b, int count_step);
t_stack		*find_max_min(t_head *head, int index_elem);
int			count_to_min_max_start(t_stack *head, int max_min);
int			count_to_min_max_end(t_stack *head, int max_min);
int			check_count_step_prev(t_stack *head, int start, int end);
int			check_count_step_next(t_stack *head, int start, int end);
void		check_all_the_end(t_head *head_a, t_head *head_b);
void		check_stack_rr_b(t_head *head_a, t_head *head_b,
								int count_step, int index_elem);
void		check_stack_rrr_b(t_head *head_a, t_head *head_b,
								int count_step, int index_elem);
t_stack		*last(t_head *head);
void		lst_delete(t_head *head);
t_stack		*lst_delete_one(t_stack *lst);
int			free_str(char **str);

#endif
