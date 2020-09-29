/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <pelease@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 00:06:12 by pelease           #+#    #+#             */
/*   Updated: 2020/06/19 01:32:13 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int			is_true_arg(char *arg, int *exist, int *len)
{
	while (*len >= 0 && ft_isspace(arg[*len]))
		(*len)--;
	while (*len >= 0)
	{
		if (!ft_isdigit(arg[*len]))
		{
			if (!ft_isdigit(arg[*len + 1]))
				return (0);
			if (is_sign(arg[*len]))
				(*len)--;
			while (*len >= 0 && ft_isspace(arg[*len]))
				(*len)--;
			if (*len < 0 || (ft_isdigit(arg[*len])
					&& ft_isspace(arg[*len + 1])))
				return (1);
			else
				return (0);
		}
		else
			(*len)--;
		*exist = 1;
	}
	return (1);
}

static int			has_duplicates(t_stack *head)
{
	t_stack		*it;

	while (head)
	{
		it = head->next;
		while (it)
		{
			if (it->val == head->val)
				return (1);
			it = it->next;
		}
		head = head->next;
	}
	return (0);
}

static int			exist_diplicate(t_stack **a)
{
	if (has_duplicates(*a))
	{
		clear_stack(a);
		return (0);
	}
	return (1);
}

int					set_stack(t_stack **a, int count, char **av, int *cnt)
{
	long int		num;
	int				exist;
	int				len;

	while (count-- > 0)
	{
		len = ft_strlen(av[count]) - 1;
		while (len >= 0)
		{
			exist = 0;
			if (!is_true_arg(av[count], &exist, &len))
				return (0);
			num = ft_atoi(av[count] + (len < 0 ? 0 : len + 1));
			if (num < -2147483648 || num > 2147483647)
				return (0);
			if (exist)
			{
				stack_push(a, num);
				if (cnt)
					(*cnt)++;
			}
		}
	}
	return (exist_diplicate(a));
}
