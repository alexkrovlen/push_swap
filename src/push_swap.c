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
	else if (stack_a->size > 3 && stack_a->size <= 5)
		no_simple_alg(stack_a);
	else if (stack_a->size > 5 && stack_a->size <= 100)
		middle_alg(stack_a, 5);
	else if (stack_a->size > 100)
		advanced_alg(stack_a, 11);
	lst_delete(stack_a);
	return (0);
}
