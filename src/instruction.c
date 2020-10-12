/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:53:51 by fjessi            #+#    #+#             */
/*   Updated: 2020/09/29 12:53:53 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_instruction(t_head *head_a, t_head *head_b, char *line)
{
	if (ft_strcmp("sa", line) == 0)
		sa_sb_instruction(head_a);
	else if (ft_strcmp("sb", line) == 0)
		sa_sb_instruction(head_b);
	else if (ft_strcmp("ss", line) == 0)
		ss_instruction(head_a, head_b);
	else if (ft_strcmp("pa", line) == 0)
		pa_pb_instruction(head_a, head_b);
	else if (ft_strcmp("pb", line) == 0)
		pa_pb_instruction(head_b, head_a);
	else if (ft_strcmp("ra", line) == 0)
		ra_rb_instruction(head_a);
	else if (ft_strcmp("rb", line) == 0)
		ra_rb_instruction(head_b);
	else if (ft_strcmp("rr", line) == 0)
		rr_instruction(head_a, head_b);
	else if (ft_strcmp("rra", line) == 0)
		rra_rrb_instruction(head_a);
	else if (ft_strcmp("rrb", line) == 0)
		rra_rrb_instruction(head_b);
	else if (ft_strcmp("rrr", line) == 0)
		rrr_instruction(head_a, head_b);
	else
		return (0);
	return (1);
}

int			check_sort(t_head *head_a, t_head *head_b)
{
	int		a;
	int		b;
	t_stack	*list;

	a = 0;
	b = 0;
	list = head_a->stack;
	while (list != NULL && list->next != NULL)
	{
		if (list->value < list->next->value)
			list = list->next;
		else
		{
			a++;
			break ;
		}
	}
	if (head_b->stack != NULL)
		b++;
	return (a + b);
}

void		instruction(t_head *head_a, t_head *head_b)
{
	char	*line;
	int		fd;

	fd = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(check_instruction(head_a, head_b, line)))
		{
			free(line);
			exit_error();
		}
		free(line);
		if (head_a->flag == 1)
			print_two_stack(head_a, head_b);
	}
	close(fd);
	if (check_sort(head_a, head_b))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}
