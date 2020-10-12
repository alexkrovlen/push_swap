/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_alg_p1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:23:20 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:09:40 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_all_the_end_help(t_head *head_b, t_head *head_a)
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

void		check_all_the_end(t_head *head_a, t_head *head_b)
{
	if (head_a->stack == NULL && head_b->stack != NULL)
	{
		if (head_b->stack->index != find_max_b(head_b))
		{
			check_all_the_end_help(head_b, head_a);
		}
		while (head_b->stack)
		{
			pa_pb_instruction(head_a, head_b);
			ft_printf("pa\n");
			if (head_a->flag == 1)
				print_two_stack(head_a, head_b);
		}
	}
}

static void	advanced_alg_start(t_head *head_a, t_head *head_b, int part)
{
	int size;
	int size_last;

	size = head_a->size / part;
	size_last = head_a->size;
	one_part(head_a, head_b, 0, size);
	one_part(head_a, head_b, size, 2 * size);
	one_part(head_a, head_b, 2 * size, 3 * size);
	one_part(head_a, head_b, 3 * size, 4 * size);
	one_part(head_a, head_b, 4 * size, 5 * size);
	one_part(head_a, head_b, 5 * size, 6 * size);
	one_part(head_a, head_b, 6 * size, 7 * size);
	one_part(head_a, head_b, 7 * size, 8 * size);
	one_part(head_a, head_b, 8 * size, 9 * size);
	one_part(head_a, head_b, 9 * size, 10 * size);
	one_part(head_a, head_b, 10 * size, size_last);
}

void		advanced_alg(t_head *head_a, int part)
{
	t_head	*head_b;

	if (head_a == NULL)
		return ;
	head_b = making_b();
	advanced_alg_start(head_a, head_b, part);
	check_all_the_end(head_a, head_b);
	if (head_a->flag == 1)
		print_two_stack(head_a, head_b);
	lst_delete(head_b);
}
