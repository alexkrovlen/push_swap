/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:25:14 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:25:16 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb_instruction(t_head *head)
{
	t_stack *tmp_first;
	t_stack *tmp_second;

	if (head->stack == NULL || head->stack->next == NULL)
		return ;
	tmp_first = head->stack;
	head->stack = head->stack->next;
	tmp_second = head->stack;
	tmp_second->prev = NULL;
	while (tmp_second->next != NULL)
		tmp_second = tmp_second->next;
	tmp_second->next = tmp_first;
	tmp_first->prev = tmp_second;
	tmp_first->next = NULL;
}

void	rr_instruction(t_head *head_a, t_head *head_b)
{
	ra_rb_instruction(head_a);
	ra_rb_instruction(head_b);
}
