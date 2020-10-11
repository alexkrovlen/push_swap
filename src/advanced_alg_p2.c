/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_alg_p2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:09:46 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:09:50 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*last(t_head *head)
{
	t_stack *tmp;

	tmp = head->stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static int	get_first_index(t_stack *head, int count)
{
	t_stack	*tmp;
	int		index;

	tmp = head;
	while (count > 0)
	{
		tmp = tmp->next;
		count--;
	}
	index = tmp->index;
	return (index);
}

static int	get_last_index(t_stack *head, int count)
{
	t_stack *tmp;
	int		index;

	tmp = head;
	while (count > 0)
	{
		tmp = tmp->prev;
		count--;
	}
	index = tmp->index;
	return (index);
}

t_stack		*find_max_min(t_head *head, int index_elem)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = head->stack;
	min = NULL;
	while (tmp != NULL)
	{
		if (tmp->index < index_elem && min == NULL)
			min = tmp;
		else if (tmp->index < index_elem && min->index < tmp->index)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void		one_part(t_head *head_a, t_head *head_b, int start, int end)
{
	int count_num;
	int count_step_s;
	int count_step_e;
	int first_index;
	int last_index;

	count_num = end - start;
	while (count_num > 0)
	{
		count_step_s = check_count_step_next(head_a->stack, start, end);
		count_step_e = check_count_step_prev(last(head_a), start, end);
		first_index = get_first_index(head_a->stack, count_step_s);
		last_index = get_last_index(last(head_a), count_step_e);
		if (count_step_s <= count_step_e + 1)
			check_stack_rr_b(head_a, head_b, count_step_s, first_index);
		else if (count_step_s > count_step_e + 1)
			check_stack_rrr_b(head_a, head_b, count_step_e, last_index);
		count_num--;
	}
}
