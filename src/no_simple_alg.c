/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_simple_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:29:21 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/10 22:29:22 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	no_simple_alg(t_head *head_a)
{
	int		size;
	t_head	*head_b;

	if (head_a == NULL)
		return ;
	if (!(head_b = (t_head *)ft_memalloc(sizeof(t_head))))
		exit_error();
	size = head_a->size / 3;
	int count_step_s;
	int count_step_e;
	while (size-- >= 0 && head_a->stack != NULL)
	{
		count_step_s = check_count_step_next(head_a->stack, 0, head_a->size / 3);
		count_step_e = check_count_step_prev(last(head_a), 0, head_a->size / 3);
		if (count_step_s <= count_step_e + 1)
		{
			while (count_step_s-- > 0)
			{
				ra_rb_instruction(head_a);
				ft_printf("ra\n");
			}
		}
		else
		{
			while (count_step_e-- >= 0)
			{
				rra_rrb_instruction(head_a);
				ft_printf("rra\n");
			}
		}
		pa_pb_instruction(head_b, head_a);
		ft_printf("pb\n");
		//simple_alg(head_b);
		print_two_stack(head_a, head_b);
		getchar();
	}
	
	//simple_alg(head_a);
	
}
