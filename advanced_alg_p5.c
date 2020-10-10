/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_alg_p5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:10:07 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:10:10 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_count_step_next(t_stack *head, int start, int end)
{
	t_stack	*tmp;
	int		count;

	tmp = head;
	count = 0;
	while (tmp)
	{
		if (tmp->index >= start && tmp->index < end)
			break ;
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int			check_count_step_prev(t_stack *head, int start, int end)
{
	t_stack	*tmp;
	int		count;

	tmp = head;
	count = 0;
	while (tmp)
	{
		if (tmp->index >= start && tmp->index < end)
			break ;
		tmp = tmp->prev;
		count++;
	}
	return (count);
}

int			count_to_min_max_start(t_stack *head, int max_min)
{
	t_stack	*tmp;
	int		count;

	tmp = head;
	count = 0;
	while (tmp != NULL)
	{
		if (tmp->index == max_min)
			return (count);
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int			count_to_min_max_end(t_stack *head, int max_min)
{
	t_stack	*tmp;
	int		count;

	tmp = head;
	count = 0;
	while (tmp != NULL)
	{
		if (tmp->index == max_min)
			return (count);
		count++;
		tmp = tmp->prev;
	}
	return (count);
}
