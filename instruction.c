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
	printf("head=%d\n", head_a->stack->value);
	if (ft_strcmp("sa", line) == 0)
		sa_sb_instruction(head_a);
	else if (ft_strcmp("sb", line) == 0)
		ss_instruction(head_a, head_b);
	else if (ft_strcmp("ss", line) == 0)
		ss_instruction(head_a, head_b);
	else if (ft_strcmp("pa", line) == 0)
		ss_instruction(head_a, head_b);
	else if (ft_strcmp("pb", line) == 0)
		ss_instruction(head_a, head_b);
	else if (ft_strcmp("ra", line) == 0)
		ss_instruction(head_a, head_b);
	else if (ft_strcmp("rb", line) == 0)
		ss_instruction(head_a, head_b);
	else if (ft_strcmp("rr", line) == 0)
		ss_instruction(head_a, head_b);
	else if (ft_strcmp("rra", line) == 0)
		ss_instruction(head_a, head_b);
	else if (ft_strcmp("rrb", line) == 0)
		ss_instruction(head_a, head_b);
	else if (ft_strcmp("rrr", line) == 0)
		ss_instruction(head_a, head_b);
	else
		return (0);
	return (1);
}

void		instruction(t_head *head_a, t_head *head_b)
{
	char	*line;
	int		fd;

	fd = 0;printf("head=%d\n", head_a->stack->value);
	while (get_next_line(fd, &line) == 1)
	{
		if (!(check_instruction(head_a, head_b, line)))
		{
			free(line);
			exit_error();
		}
		free(line);
	}
	close(fd);
	printf("head_a = %d\n", head_a->stack->value);
	printf("DONE\n");
}
