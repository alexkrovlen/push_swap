/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 01:08:32 by pelease           #+#    #+#             */
/*   Updated: 2020/06/14 01:23:38 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		reverse_rotate(t_stack **a, t_stack **b,
		t_look *st, int counter)
{
	while (counter-- > 0)
	{
		if ((*b)->order != st->next)
			rev_rotate(a, b, 'r', st);
		else
			rev_rotate(a, b, 'a', st);
	}
}

void			push_stack_a(t_stack **a, t_stack **b, t_look *st, int n)
{
	int		i;

	i = n;
	while (n-- > 0)
	{
		(*b)->flag = st->flag;
		(*b)->is_sorted = 1;
		st->next++;
		push(a, b, 'a', st);
		rotate(a, b, 'a', st);
	}
	st->b_cnt -= i;
}

void			push_stack_b(t_stack **a, t_stack **b, t_look *st, int flag)
{
	int			i;
	int			counter;

	i = st->mid - st->next + 1;
	counter = 0;
	while (i > 0 && flag == (*a)->flag && !(*a)->is_sorted)
		if ((*a)->order == st->next && (*a)->prev->order == st->next - 1)
		{
			i -= (*a)->order <= st->mid;
			(*a)->is_sorted = 1;
			rotate(a, b, 'a', st);
			st->next++;
		}
		else if ((*a)->order <= st->mid && ++st->b_cnt)
		{
			push(a, b, 'b', st);
			i--;
		}
		else
		{
			counter++;
			rotate(a, b, 'a', st);
		}
	if (st->next != 1)
		reverse_rotate(a, b, st, counter);
}

void			move_up(t_stack **b, t_stack **a, t_look *st)
{
	int		i;

	i = st->b_cnt - (st->mid - st->next);
	while (i > 0 && *b)
	{
		if ((*b)->order == st->next)
		{
			i -= (*b)->order >= st->mid;
			push_stack_a(a, b, st, 1);
		}
		else if ((*b)->order >= st->mid)
		{
			(*b)->flag = st->flag;
			push(a, b, 'a', st);
			st->b_cnt--;
			i--;
		}
		else
			rotate(a, b, 'b', st);
	}
}
