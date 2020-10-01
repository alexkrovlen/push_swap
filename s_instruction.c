/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_insruction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:13:08 by fjessi            #+#    #+#             */
/*   Updated: 2020/09/29 14:13:10 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb_instruction(t_head *head)
{
	t_stack		*list;
	int			temp;

	list = head->stack;
	if (list == NULL || head->size == 1)
		return ;
	temp = list->value;
	list->value = list->next->value;
	list->next->value = temp;
	temp = list->index;
	list->index = list->next->index;
	list->next->index = temp;
	print_stack(head);
}

void	ss_instruction(t_head *head_a, t_head *head_b)
{
	sa_sb_instruction(head_a);
	sa_sb_instruction(head_b);
}