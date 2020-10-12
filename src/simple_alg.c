/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:25:51 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:25:53 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	simple_two(t_stack *list, t_stack *list_middle, t_head *head_a)
{
	if (list->index < list_middle->index \
		&& list_middle->index > list_middle->next->index \
		&& list->index < list_middle->next->index)
	{
		sa_sb_instruction(head_a);
		ft_printf("sa\n");
		if (head_a->flag == 1 && head_a->size <= 3)
			print_two_stack(head_a, NULL);
		ra_rb_instruction(head_a);
		ft_printf("ra\n");
		if (head_a->flag == 1 && head_a->size <= 3)
			print_two_stack(head_a, NULL);
	}
	else if (list->index < list_middle->index \
		&& list_middle->index > list_middle->next->index \
		&& list->index > list_middle->next->index)
	{
		rra_rrb_instruction(head_a);
		ft_printf("rra\n");
		if (head_a->flag == 1 && head_a->size <= 3)
			print_two_stack(head_a, NULL);
	}
}

static void	simple_one(t_stack *list, t_stack *list_middle, t_head *head_a)
{
	if (list->index > list_middle->index \
		&& list_middle->index < list_middle->next->index \
		&& list->index < list_middle->next->index)
	{
		print_sa(head_a);
	}
	else if (list->index > list_middle->index \
		&& list_middle->index > list_middle->next->index \
		&& list->index > list_middle->next->index)
	{
		sa_sb_instruction(head_a);
		ft_printf("sa\n");
		if (head_a->flag == 1 && head_a->size <= 3)
			print_two_stack(head_a, NULL);
		rra_rrb_instruction(head_a);
		ft_printf("rra\n");
		if (head_a->flag == 1 && head_a->size <= 3)
			print_two_stack(head_a, NULL);
	}
	else if (list->index > list_middle->index \
		&& list_middle->index < list_middle->next->index \
		&& list->index > list_middle->next->index)
	{
		print_ra(head_a, NULL);
	}
}

void		simple_alg(t_head *head_a)
{
	t_stack *list;
	t_stack *list_middle;

	if (head_a->stack == NULL)
		return ;
	list = head_a->stack;
	if (head_a->stack->next->next != NULL)
	{
		list_middle = head_a->stack->next;
		if (list->index < list_middle->index \
			&& list_middle->index < list_middle->next->index)
			return ;
		if (list->index > list_middle->index)
			simple_one(list, list_middle, head_a);
		else if (list->index < list_middle->index)
			simple_two(list, list_middle, head_a);
	}
	else
	{
		sa_sb_instruction(head_a);
		ft_printf("sa\n");
		if (head_a->flag == 1 && head_a->size < 3)
			print_two_stack(head_a, NULL);
	}
}
