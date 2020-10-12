/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:13:08 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/02 17:23:39 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_head	*stack_a;
	t_head	*stack_b;

	if (ac >= 2)
	{
		if (!(stack_a = making_stack(ac, av)))
			exit_error();
		if (!(stack_b = (t_head *)ft_memalloc(sizeof(t_head))))
			exit_error();
		stack_b->stack = NULL;
		stack_b->size = 0;
		instruction(stack_a, stack_b);
		lst_delete(stack_a);
		lst_delete(stack_b);
	}
	return (0);
}
