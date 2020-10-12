/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:14:15 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:14:17 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	middle_alg_start(t_head *head_a, t_head *head_b, int part)
{
	int size;
	int size_last;

	size = head_a->size / part;
	size_last = head_a->size;
	one_part(head_a, head_b, 0, size);
	one_part(head_a, head_b, size, 2 * size);
	one_part(head_a, head_b, 2 * size, 3 * size);
	one_part(head_a, head_b, 3 * size, 4 * size);
	one_part(head_a, head_b, 4 * size, size_last);
}

void		middle_alg(t_head *head_a, int part)
{
	t_head	*head_b;

	if (head_a == NULL)
		return ;
	head_b = making_b();
	middle_alg_start(head_a, head_b, part);
	check_all_the_end(head_a, head_b);
	if (head_a->flag == 1)
		print_two_stack(head_a, head_b);
	lst_delete(head_b);
}
