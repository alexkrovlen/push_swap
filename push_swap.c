/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:27:52 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/02 17:35:29 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_head	*stack_a;
	///t_head  *stack_b;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (!(stack_a = making_stack(ac, av)))
		exit_error();
    if (stack_a->size <= 5)
        simple_alg(stack_a);
    else if (stack_a->size > 5 && stack_a->size <= 100)
        middle_alg(stack_a);
    else if (stack_a->size > 100)
        advanced_alg(stack_a);
	//printf("push_swap_ostanovochka na vse ok\n");
	return (0);
}

/*
    gcc -Wall -Wextra -Werror s_instruction.c p_instruction.c rr_instruction.c rrr_instruction.c instruction.c exit_error.c push_swap.c validation.c push_swap.h check_repeat.c making_stack.c sort_massiv.c get_index.c ./ft_printf/libftprintf.a
*/
