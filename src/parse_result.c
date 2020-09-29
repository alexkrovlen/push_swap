/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 00:29:25 by pelease           #+#    #+#             */
/*   Updated: 2020/06/13 00:38:26 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			parse_result(t_stack *a, t_stack *b)
{
	t_stack		*head;

	head = a;
	if (b)
	{
		clear_stack(&b);
		clear_stack(&a);
		write(1, "KO\n", 3);
		return ;
	}
	while (a && a->next)
	{
		if (a->val > a->next->val)
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		a = a->next;
	}
	write(1, "OK\n", 3);
	clear_stack(&head);
}
