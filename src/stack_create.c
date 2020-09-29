/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:13:53 by pelease           #+#    #+#             */
/*   Updated: 2020/06/16 00:37:20 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*stack_create(int value)
{
	t_stack		*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	stack->next = NULL;
	stack->prev = NULL;
	stack->val = value;
	stack->flag = 0;
	stack->order = 0;
	stack->is_sorted = 0;
	return (stack);
}

void			stack_push(t_stack **head, int value)
{
	t_stack		*new;
	t_stack		*last;

	if (head == NULL)
		return ;
	if (!(new = stack_create(value)))
		return ;
	last = *head;
	while (last && last->next)
		last = last->next;
	new->next = *head;
	new->prev = last;
	if (*head)
		(*head)->prev = new;
	*head = new;
}

void			stack_add(t_stack **dest, t_stack *src)
{
	t_stack		*last;

	if (!dest || !src)
		return ;
	last = *dest;
	while (last && last->next)
		last = last->next;
	src->next = *dest;
	src->prev = last;
	*dest = src;
}

t_stack			*stack_pop(t_stack **head)
{
	t_stack		*el;

	if (!head || !*head)
		return (NULL);
	el = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = el->prev;
	el->next = NULL;
	el->prev = NULL;
	return (el);
}

void			clear_stack(t_stack **head)
{
	t_stack		*del;

	if (!head || !*head)
		return ;
	while (*head)
	{
		del = *head;
		*head = (*head)->next;
		free(del);
	}
}
