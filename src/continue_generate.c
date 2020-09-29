/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_generate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 01:14:58 by pelease           #+#    #+#             */
/*   Updated: 2020/06/14 01:34:07 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		handle_stack_a(t_stack **a, t_stack **b, t_look *st)
{
	st->max = st->mid;
	st->mid = (st->max - st->next) / 2 + st->next;
	st->flag++;
	if (st->b_cnt == 3)
	{
		stack_sort(a, b, st, 'b');
		push_stack_a(a, b, st, 3);
	}
	else if (st->b_cnt == 2)
	{
		if ((*b)->order > (*b)->next->order)
			swap(a, b, 'b', st);
		push_stack_a(a, b, st, 2);
	}
	else
		move_up(b, a, st);
}

static void		sorting(t_stack **a, t_stack **b, t_look *st, int stop)
{
	st->mid = st->cnt / 2 + st->next;
	push_stack_b(a, b, st, (*a)->flag);
	while (*b)
		handle_stack_a(a, b, st);
	if (st->next <= st->cnt && (stop || stop < 0))
		sorting(a, b, st, stop - 1);
}

void			continue_generate(t_stack **a, t_stack **b,
					t_look *st, int stop)
{
	if (st->a_cnt > 5)
		sorting(a, b, st, stop);
	else
		particular_sort(a, b, st);
}
