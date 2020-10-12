/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_simple_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:29:21 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:29:22 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_min_max(t_head *head, int index_elem)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = head->stack;
	max = NULL;
	while (tmp != NULL)
	{
		if (tmp->index > index_elem && max == NULL)
			max = tmp;
		else if (tmp->index > index_elem && max->index > tmp->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

static void		no_simple_alg_two(t_head *head_a, t_stack *min_max,
									t_head *head_b)
{
	int		c_step_s;
	int		c_step_e;

	c_step_s = count_to_min_max_start(head_a->stack, min_max->index);
	c_step_e = count_to_min_max_end(last(head_a), min_max->index);
	if (c_step_s <= c_step_e + 1)
	{
		while (head_a->stack->index != min_max->index)
		{
			ra_rb_instruction(head_a);
			ft_printf("ra\n");
			if (head_a->flag == 1)
				print_two_stack(head_a, head_b);
		}
	}
	else
	{
		while (head_a->stack->index != min_max->index)
		{
			rra_rrb_instruction(head_a);
			ft_printf("rra\n");
			if (head_a->flag == 1)
				print_two_stack(head_a, head_b);
		}
	}
}

static void		no_simple_alg_one(t_head *head_a, t_head *head_b)
{
	t_stack	*min_max;

	min_max = find_min_max(head_a, head_b->stack->index);
	if (min_max != NULL)
	{
		no_simple_alg_two(head_a, min_max, head_b);
	}
	else
	{
		while (head_a->stack->index != find_min_b(head_a->stack))
		{
			ra_rb_instruction(head_a);
			ft_printf("ra\n");
			if (head_a->flag == 1)
				print_two_stack(head_a, head_b);
		}
	}
	pa_pb_instruction(head_a, head_b);
	ft_printf("pa\n");
	if (head_a->flag == 1)
		print_two_stack(head_a, head_b);
}

void			no_simple_alg(t_head *head_a)
{
	int		size;
	t_head	*head_b;

	if (head_a == NULL)
		return ;
	head_b = making_b();
	size = head_a->size - 3;
	while (size-- > 0)
	{
		pa_pb_instruction(head_b, head_a);
		ft_printf("pb\n");
		if (head_a->flag == 1)
			print_two_stack(head_a, head_b);
	}
	simple_alg(head_a);
	if (head_a->flag == 1)
		print_two_stack(head_a, head_b);
	while (head_b->stack)
		no_simple_alg_one(head_a, head_b);
	while (head_a->stack->index != find_min_b(head_a->stack))
	{
		print_ra(head_a, head_b);
	}
	lst_delete(head_b);
}
