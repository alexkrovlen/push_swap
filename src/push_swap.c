/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:27:52 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:21:41 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_to_sort(t_head *stack_a)
{
	t_stack *list;
	int		i;

	i = 0;
	list = stack_a->stack;
	while (list->next != NULL)
	{
		if (list->index < list->next->index && list->next != NULL)
		{
			list = list->next;
			i = 1;
		}
		else
		{
			i = 0;
			break ;
		}
	}
	return (i);
}

int			main(int ac, char **av)
{
	t_head	*stack_a;

	if (!(stack_a = making_stack(ac, av)))
		exit_error();
	if (check_to_sort(stack_a) == 1 || stack_a->size == 1)
		return (0);
	if (stack_a->size <= 3)
		simple_alg(stack_a);
	else if (stack_a->size > 3 && stack_a->size <= 10)
		no_simple_alg(stack_a);
	else if (stack_a->size > 10 && stack_a->size <= 100)
		middle_alg(stack_a, 5);
	else if (stack_a->size > 100)
		advanced_alg(stack_a, 11);
	lst_delete(stack_a);
	return (0);
}
/*
   gcc -Wall -Wextra -Werror delete_head.c print_stack.c simple_alg.c no_simple_alg.c middle_alg.c advanced_alg_p1.c advanced_alg_p2.c advanced_alg_p3.c advanced_alg_p4.c advanced_alg_p5.c advanced_alg_p6.c s_instruction.c p_instruction.c rr_instruction.c rrr_instruction.c instruction.c exit_error.c push_swap.c validation.c push_swap.h check_repeat.c making_stack.c sort_massiv.c get_index.c ./ft_printf/libftprintf.a
   */
