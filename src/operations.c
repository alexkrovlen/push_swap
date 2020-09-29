/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <pelease@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 10:10:33 by pelease           #+#    #+#             */
/*   Updated: 2020/06/18 19:46:13 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		update_state(t_look *mn, char *cmd)
{
	if (!mn->head)
	{
		mn->head = ft_lstnew(cmd, 5);
		mn->last = mn->head;
	}
	else
	{
		mn->last->next = ft_lstnew(cmd, 5);
		mn->last = mn->last->next;
	}
}

void			swap(t_stack **a, t_stack **b, char c, t_look *mn)
{
	char	cmd[3];

	cmd[2] = '\0';
	cmd[1] = c;
	cmd[0] = 's';
	if (cmd[1] == 'a')
		stack_swap(a);
	else if (cmd[1] == 'b')
		stack_swap(b);
	else if (cmd[1] == 's')
	{
		stack_swap(a);
		stack_swap(b);
	}
	if (mn)
		update_state(mn, cmd);
}

void			push(t_stack **a, t_stack **b, char c, t_look *mn)
{
	char	cmd[3];

	cmd[2] = '\0';
	cmd[1] = c;
	cmd[0] = 'p';
	if (cmd[1] == 'a' && *b)
		stack_add(a, stack_pop(b));
	else if (cmd[1] == 'b' && *a)
		stack_add(b, stack_pop(a));
	if (mn)
		update_state(mn, cmd);
}

void			rotate(t_stack **a, t_stack **b, char c, t_look *mn)
{
	char	cmd[3];

	cmd[2] = '\0';
	cmd[1] = c;
	cmd[0] = 'r';
	if (cmd[1] == 'a')
		stack_rotate(a, 0);
	else if (cmd[1] == 'b')
		stack_rotate(b, 0);
	else if (cmd[1] == 'r')
	{
		stack_rotate(a, 0);
		stack_rotate(b, 0);
	}
	if (mn)
		update_state(mn, cmd);
}

void			rev_rotate(t_stack **a, t_stack **b, char c, t_look *mn)
{
	char	cmd[4];

	cmd[3] = '\0';
	cmd[2] = c;
	cmd[1] = 'r';
	cmd[0] = 'r';
	if (cmd[1] == 'r' && cmd[2] == 'a')
		stack_rotate(a, 1);
	else if (cmd[1] == 'r' && cmd[2] == 'b')
		stack_rotate(b, 1);
	else if (cmd[1] == 'r' && cmd[2] == 'r')
	{
		stack_rotate(a, 1);
		stack_rotate(b, 1);
	}
	if (mn)
		update_state(mn, cmd);
}
