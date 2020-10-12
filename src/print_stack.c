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

static t_stack	*print_help(t_stack *aa)
{
	ft_printf(" {bold_green}%d   {black}#{normal}\n", aa->value);
	aa = aa->next;
	return (aa);
}

void			print_two_stack(t_head *a, t_head *b)
{
	t_stack	*aa;
	t_stack	*bb;

	aa = a->stack;
	if (b != NULL)
		bb = b->stack;
	else
		bb = NULL;
	ft_printf("\n{bold_green} a   {bold_aquamarine}b\n");
	ft_printf("{bold_blue}________{normal}\n\n");
	while (aa || bb)
	{
		if (aa && bb)
		{
			ft_printf(" {bold_green}%d   {bold_aquamarine}%d{normal}\n",
													aa->value, bb->value);
			aa = aa->next;
			bb = bb->next;
		}
		else if (aa && bb == NULL)
			aa = print_help(aa);
		else if (aa == NULL && bb)
			bb = print_help(bb);
	}
	ft_printf("{bold_blue}________{normal}\n");
}

void			print_rb(t_head *head_b, t_head *head_a)
{
	ra_rb_instruction(head_b);
	ft_printf("rb\n");
	if (head_a->flag == 1)
		print_two_stack(head_a, head_b);
}

void			print_ra(t_head *head_a, t_head *head_b)
{
	ra_rb_instruction(head_a);
	ft_printf("ra\n");
	if (head_a->flag == 1 && head_a->size <= 3)
		print_two_stack(head_a, NULL);
	else if (head_a->flag == 1)
		print_two_stack(head_a, head_b);
}

void			print_sa(t_head *head_a)
{
	sa_sb_instruction(head_a);
	ft_printf("sa\n");
	if (head_a->flag == 1 && head_a->size <= 3)
		print_two_stack(head_a, NULL);
}
