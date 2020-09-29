/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <pelease@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 21:37:46 by pelease           #+#    #+#             */
/*   Updated: 2020/06/18 22:42:59 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		set_array(t_stack *stk, int **sorted, int cnt)
{
	int			i;

	if (!cnt)
		exit(1);
	if (!(*sorted = (int *)malloc(sizeof(int) * cnt)))
		return ;
	i = 0;
	while (stk)
	{
		(*sorted)[i] = stk->val;
		i++;
		stk = stk->next;
	}
}

static void		set_order(t_stack *a, int *sorted, int n)
{
	int			i;

	while (a)
	{
		i = 0;
		while (i < n && sorted[i] != a->val)
			i++;
		if (i != n)
		{
			a->order = i + 1;
			a->flag = 0;
		}
		a = a->next;
	}
	free(sorted);
}

static void		init_look(t_look *look, int ac)
{
	look->next = 1;
	look->max = ac;
	look->flag = 0;
	look->b_cnt = 0;
	look->cnt = ac;
	look->last = NULL;
	look->head = NULL;
}

int				main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			*sorted;
	t_look		look;

	a = NULL;
	b = NULL;
	look.a_cnt = 0;
	sorted = NULL;
	if (!set_stack(&a, ac - 1, av + 1, &(look.a_cnt)))
	{
		if (a)
			clear_stack(&a);
		write(2, "Error\n", 6);
		exit(0);
	}
	set_array(a, &sorted, look.a_cnt);
	init_look(&look, look.a_cnt);
	array_sort(sorted, 0, look.a_cnt - 1);
	set_order(a, sorted, look.a_cnt);
	if (!stack_sorted(a))
		continue_generate(&a, &b, &look, -1);
	parse_pushswap(&look, &a, look.head);
	return (0);
}
