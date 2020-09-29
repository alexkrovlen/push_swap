/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:13:53 by pelease           #+#    #+#             */
/*   Updated: 2020/06/16 21:42:18 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			stack_swap(t_stack **stck)
{
	t_stack		*head;

	if (!stck || !*stck || !(*stck)->next)
		return ;
	head = *stck;
	*stck = (*stck)->next;
	if (head->prev == *stck)
		(*stck)->prev = head;
	else
		(*stck)->prev = head->prev;
	head->next = (*stck)->next;
	if ((*stck)->next)
		(*stck)->next->prev = head;
	head->prev = *stck;
	(*stck)->next = head;
}

void			stack_rotate(t_stack **head, int rev)
{
	t_stack		*first;
	t_stack		*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = first->prev;
	if (!rev)
	{
		last->next = first;
		*head = (*head)->next;
		(*head)->prev = first;
		first->next = NULL;
	}
	else
	{
		while ((*head)->next != last)
			*head = (*head)->next;
		(*head)->next = NULL;
		last->next = first;
		last->prev = *head;
		*head = last;
	}
}

static void		reverse_print(t_stack *head)
{
	t_stack		*first;

	first = head;
	head = head->prev;
	while (head && head != first)
	{
		ft_putnbr((int)head->val);
		write(1, " => ", 4);
		head = head->prev;
	}
	ft_putnbr(first->val);
	write(1, " => (NULL)\n", 11);
}

void			ft_stk_print(t_stack *head, int rev)
{
	if (!head)
	{
		write(1, "(NULL)\n", 7);
		return ;
	}
	if (!rev)
		while (head)
		{
			ft_putnbr((int)head->val);
			if (head->next)
				write(1, " => ", 4);
			else
				write(1, " => (NULL)\n", 11);
			head = head->next;
		}
	else
		reverse_print(head);
}

int				stack_sorted(t_stack *stk)
{
	while (stk && stk->next)
	{
		if (stk->val >= stk->next->val)
			return (0);
		stk = stk->next;
	}
	return (1);
}
