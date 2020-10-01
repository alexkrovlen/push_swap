/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:13:08 by fjessi            #+#    #+#             */
/*   Updated: 2020/09/29 12:53:43 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_head *a)
{
    t_stack *b;

    b = a->stack;
    while(b)
    {
        printf("%d\n", b->value);
        b = b->next;
        //getchar();
    }

}

int     main(int ac, char **av)
{
    t_head  *stack_a;
    t_head  *stack_b;
    //t_buf   *head;
    //int test;

    if (!(stack_a = making_stack(ac, av)))
        exit_error();
    //print_stack(stack_a);
	if (!(stack_b = (t_head *)ft_memalloc(sizeof(t_head))))
		exit_error();
	stack_b->stack = NULL;
	stack_b->size = 0;
	instruction(stack_a, stack_b);
    printf("checker_ostanovochka na vse ok\n");
    
    return (0);
}

/*

gcc -Wall -Wextra -Werror s_instruction.c p_instruction.c rr_instruction.c rrr_instruction.c instruction.c exit_error.c checker.c validation.c push_swap.h check_repeat.c making_stack.c sort_massiv.c get_index.c ./ft_printf/libftprintf.a

*/

