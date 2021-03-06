/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_instruction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:25:03 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:25:08 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_pb_instruction(t_head *to, t_head *from)
{
	t_stack	*tmp;
	t_stack	*tmp_h;

	if (from->stack == NULL)
		return ;
	tmp = from->stack;
	from->stack = from->stack->next;
	if (from->stack)
		from->stack->prev = NULL;
	tmp_h = to->stack;
	tmp->next = tmp_h;
	to->stack = tmp;
	to->stack->prev = NULL;
	if (to->stack->next)
		to->stack->next->prev = to->stack;
}
