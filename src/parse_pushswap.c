/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pushswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 01:05:52 by pelease           #+#    #+#             */
/*   Updated: 2020/06/14 01:36:20 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_cmds(char *s1, char *s2, char c)
{
	char		cmd1[3];
	char		cmd2[3];

	cmd1[1] = 'a';
	cmd1[2] = '\0';
	cmd2[1] = 'b';
	cmd2[2] = '\0';
	cmd1[0] = c;
	cmd2[0] = c;
	if ((!ft_strcmp(s1, cmd1) &&
		!ft_strcmp(s2, cmd2))
		|| (!ft_strcmp(s1, cmd2) &&
		!ft_strcmp(s2, cmd1)))
	{
		cmd1[1] = c;
		ft_printf("%s\n", cmd1);
		return (1);
	}
	return (0);
}

static int		check_print(char *s1, char *s2)
{
	if ((!ft_strcmp(s1, "pa") && !ft_strcmp(s2, "pb")) ||
		(!ft_strcmp(s1, "pb") && !ft_strcmp(s2, "pa")) ||
		(!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rra")) ||
		(!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "ra")) ||
		(!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "rrb")) ||
		(!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rb")))
		return (1);
	return (0);
}

void			parse_pushswap(t_look *st, t_stack **a, t_list *lst)
{
	while (lst && lst->next)
	{
		if (check_cmds(lst->content, lst->next->content, 's'))
			lst = lst->next;
		else if (check_cmds(lst->content, lst->next->content, 'r'))
			lst = lst->next;
		else if (check_print(lst->content, lst->next->content))
			lst = lst->next;
		else
		{
			ft_putstr(lst->content);
			write(1, "\n", 1);
		}
		lst = lst->next;
	}
	if (lst)
	{
		ft_putstr(lst->content);
		write(1, "\n", 1);
	}
	clear_stack(a);
	clear_list(&st->head);
}
