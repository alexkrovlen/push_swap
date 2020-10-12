/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_alg_p3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:09:54 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:09:57 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_stack_rr_b_three(t_head *head_b, t_head *head_a)
{
	int c_step_max_s;
	int c_step_max_e;

	c_step_max_s = count_to_min_max_start(head_b->stack, find_max_b(head_b));
	c_step_max_e = count_to_min_max_end(last(head_b), find_max_b(head_b));
	if (c_step_max_s <= c_step_max_e + 1)
	{
		while (head_b->stack->index != find_max_b(head_b))
		{
			ra_rb_instruction(head_b);
			ft_printf("rb\n");
			if (head_a->flag == 1)
				print_two_stack(head_a, head_b);
		}
	}
	else
	{
		while (head_b->stack->index != find_max_b(head_b))
		{
			rra_rrb_instruction(head_b);
			ft_printf("rrb\n");
			if (head_a->flag == 1)
				print_two_stack(head_a, head_b);
		}
	}
}

static void	check_stack_rr_b_four(t_head *head_a, t_head *head_b,
									int count_step, t_stack *max_min)
{
	int c_step_s;
	int c_step_e;

	c_step_s = count_to_min_max_start(head_b->stack, max_min->index);
	c_step_e = count_to_min_max_end(last(head_b), max_min->index);
	if (c_step_s <= c_step_e + 1)
	{
		while (head_b->stack->index != max_min->index)
		{
			print_rb(head_b, head_a);
		}
		push_to_rr_b(head_a, head_b, count_step);
	}
	else
	{
		while (head_b->stack->index != max_min->index)
		{
			rra_rrb_instruction(head_b);
			ft_printf("rrb\n");
			if (head_a->flag == 1)
				print_two_stack(head_a, head_b);
		}
		push_to_rr_b(head_a, head_b, count_step);
	}
}

static void	check_stack_rr_b_two(t_head *head_a, t_head *head_b,
									int count_step, int index_elem)
{
	int		min;
	t_stack	*max_min;

	max_min = find_max_min(head_b, index_elem);
	min = find_min_b(head_b->stack);
	if (min > index_elem)
	{
		check_stack_rr_b_three(head_b, head_a);
	}
	else
	{
		check_stack_rr_b_four(head_a, head_b, count_step, max_min);
	}
}

static void	check_stack_rr_b_one(t_head *head_b, t_head *head_a)
{
	int c_step_max_s;
	int c_step_max_e;

	c_step_max_s = count_to_min_max_start(head_b->stack, find_max_b(head_b));
	c_step_max_e = count_to_min_max_end(last(head_b), find_max_b(head_b));
	if (c_step_max_s <= c_step_max_e + 1)
	{
		while (head_b->stack->index != find_max_b(head_b))
		{
			ra_rb_instruction(head_b);
			ft_printf("rb\n");
			if (head_a->flag == 1)
				print_two_stack(head_a, head_b);
		}
	}
	else
	{
		while (head_b->stack->index != find_max_b(head_b))
		{
			rra_rrb_instruction(head_b);
			ft_printf("rrb\n");
			if (head_a->flag == 1)
				print_two_stack(head_a, head_b);
		}
	}
}

void		check_stack_rr_b(t_head *head_a, t_head *head_b,
								int count_step, int index_elem)
{
	if (head_b->stack == NULL)
		push_to_rr_b(head_a, head_b, count_step);
	else
	{
		if (find_max_min(head_b, index_elem) == NULL)
		{
			check_stack_rr_b_one(head_b, head_a);
			push_to_rr_b(head_a, head_b, count_step);
		}
		else
		{
			check_stack_rr_b_two(head_a, head_b, count_step, index_elem);
		}
	}
}
