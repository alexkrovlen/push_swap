/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_alg_p6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:10:15 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:10:17 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_rr_b(t_head *head_a, t_head *head_b, int count_step)
{
	while (count_step > 0)
	{
		ra_rb_instruction(head_a);
		ft_printf("ra\n");
		count_step--;
	}
	pa_pb_instruction(head_b, head_a);
	ft_printf("pb\n");
	head_a->size--;
}

void	push_to_rrr_b(t_head *head_a, t_head *head_b, int count_step)
{
	while (count_step > 0)
	{
		rra_rrb_instruction(head_a);
		ft_printf("rra\n");
		count_step--;
	}
	rra_rrb_instruction(head_a);
	ft_printf("rra\n");
	pa_pb_instruction(head_b, head_a);
	ft_printf("pb\n");
	head_a->size--;
}

int		find_min_b(t_stack *head)
{
	t_stack	*tmp;
	int		min;

	tmp = head;
	min = 0;
	while (tmp != NULL)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int		find_max_b(t_head *head)
{
	t_stack	*tmp;
	int		max;

	tmp = head->stack;
	max = 0;
	while (tmp != NULL)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}
