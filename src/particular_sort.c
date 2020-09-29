/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particular_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <pelease@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 01:18:14 by pelease           #+#    #+#             */
/*   Updated: 2020/06/19 01:29:19 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			stack_sort(t_stack **a, t_stack **b, t_look *st, char c)
{
	int			val3;
	int			val2;

	val2 = (*b)->next->order;
	val3 = (*b)->next->next->order;
	if ((*b)->order > val2 && val2 < val3 && (*b)->order > val3)
		rotate(a, b, c, st);
	else if ((*b)->order > val2 && val2 < val3 && (*b)->order < val3)
		swap(a, b, c, st);
	else if ((*b)->order < val2 && val2 > val3 && (*b)->order > val3)
		rev_rotate(a, b, c, st);
	else if ((*b)->order > val2 && val2 > val3 && (*b)->order > val3)
	{
		rotate(a, b, c, st);
		swap(a, b, c, st);
	}
	else if ((*b)->order < val2 && val2 > val3 && (*b)->order < val3)
	{
		rev_rotate(a, b, c, st);
		swap(a, b, c, st);
	}
}

void			four_sorting(t_stack **a, t_stack **b, t_look *st)
{
	while ((*a)->order != st->next)
		rotate(a, b, 'a', st);
	push(a, b, 'b', st);
	stack_sort(b, a, st, 'a');
	push(a, b, 'a', st);
}

void			five_sorting(t_stack **a, t_stack **b, t_look *st)
{
	while ((*a)->order != 1)
		rotate(a, b, 'a', st);
	push(a, b, 'b', st);
	st->next++;
	if ((*a)->next->next->next->order == st->next)
		rev_rotate(a, b, 'a', st);
	four_sorting(a, b, st);
	push(a, b, 'a', st);
}

void			particular_sort(t_stack **a, t_stack **b, t_look *st)
{
	if (st->a_cnt == 3)
		stack_sort(b, a, st, 'a');
	else if (st->a_cnt == 2)
		swap(a, b, 'a', st);
	else if (st->a_cnt == 4)
		four_sorting(a, b, st);
	else
		five_sorting(a, b, st);
}
