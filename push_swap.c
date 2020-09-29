/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:27:52 by fjessi            #+#    #+#             */
/*   Updated: 2020/02/25 14:27:54 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int     main(int ac, char **av)
{
    t_head  *stack_a;
    ///t_head  *stack_b;
    int i;
    int j;
    //t_buf   *head;
    //int test;

    i = 1;
    j = 0;
    if (!(stack_a = making_stack(ac, av)))
        exit_error();
    printf("push_swap_ostanovochka na vse ok\n");
    
    return (0);
}

/*

gcc -Wall -Wextra -Werror exit_error.c push_swap.c validation.c push_swap.h check_repeat.c making_stack.c sort_massiv.c get_index.c ./ft_printf/libftprintf.a

*/