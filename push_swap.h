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

/*
typedef struct		s_command
{
	char				*cmd;
	struct s_command	*next;
}					t_command;
*/

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
void		middle_alg(t_head *head_a);
void		advanced_alg(t_head *head_a);
void		lst_delete(t_head *head);
t_stack		*lst_delete_one(t_stack *lst);
int			free_str(char **str);

#endif
