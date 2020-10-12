/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:24:04 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:24:07 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*lst_delete_one(t_stack *lst)
{
	t_stack	*next;
	t_stack	*prev;

	prev = lst->prev;
	next = lst->next;
	if (prev != NULL)
		prev->next = lst->next;
	if (next != NULL)
		next->prev = lst->prev;
	free(lst);
	return (next);
}

void		lst_delete(t_head *head)
{
	if (!head)
		return ;
	while (head->stack)
	{
		head->stack = lst_delete_one(head->stack);
	}
	free(head);
}
