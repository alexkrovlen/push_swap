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

	printf("val=%d\n", head->stack->value);
	list = head->stack;
	if (list == NULL || head->size == 1)
		return ;
	temp = list->value;
	printf("111111\n");
	printf("tmp=%d\n", temp);
	getchar();
	printf("next=%d\n", list->next->value);
	getchar();
	list->value = list->next->value;
	printf("222222\n");
	list->next->value = temp;
	printf("333333\n");
	print_stack(head);
	printf("sa_sb_instruction!!!\n");
	
}

void	ss_instruction(t_head *head_a, t_head *head_b)
{
	if (head_a && head_b)
		printf("trenirovka_ss_instruction!!!\n");
}