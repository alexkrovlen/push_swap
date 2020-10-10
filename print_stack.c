/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:26:36 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:26:38 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_index(t_head *a)
{
	t_stack	*b;

	b = a->stack;
	while (b)
	{
		printf("%3d----%3d\n", b->value, b->index);
		b = b->next;
	}
}

void	print_stack(t_head *a)
{
	t_stack	*b;

	b = a->stack;
	while (b)
	{
		printf("%d\n", b->value);
		b = b->next;
	}
}

void	print_two_stack(t_head *a, t_head *b)
{
	t_stack	*aa;
	t_stack	*bb;

	aa = a->stack;
	bb = b->stack;
	printf("a    b\n_______\n");
	while (aa || bb)
	{
		if (aa && bb)
		{
			printf("%d   %d\n", aa->value, bb->value);
			aa = aa->next;
			bb = bb->next;
		}
		else if (aa && bb == NULL)
		{
			printf("%d   #\n", aa->value);
			aa = aa->next;
		}
		else if (aa == NULL && bb)
		{
			printf("#   %d\n", bb->value);
			bb = bb->next;
		}
	}
}
