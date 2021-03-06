/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_repeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:45:28 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/02 17:14:43 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			count_number(char **av, int flag)
{
	int		i;
	int		j;
	int		count;
	char	**str;

	i = 1 + flag;
	count = 0;
	while (av[i])
	{
		j = 0;
		str = ft_strsplit(av[i], ' ');
		while (str[j++])
			count++;
		while (--j != -1)
			free(str[j]);
		free(str);
		i++;
	}
	return (count);
}

static int	*write_stack(int count, int *stack, char **av, int flag)
{
	int		i;
	int		j;
	int		n;
	char	**str;

	i = 0;
	j = 0;
	n = 1 + flag;
	while (i != count)
	{
		j = 0;
		str = ft_strsplit(av[n++], ' ');
		while (str[j] != NULL)
		{
			if (ft_atoi_new(str[j]) >= INT_MIN &&\
					ft_atoi_new(str[j]) <= INT_MAX)
				stack[i++] = ft_atoi_new(str[j++]);
			else
				exit_error();
		}
		while (--j != -1)
			free(str[j]);
		free(str);
	}
	return (stack);
}

static int	check_repeat_number(int *stack, int count)
{
	int		i;
	int		j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			*check_repeat(char **av, int flag)
{
	int		count;
	int		*stack;

	count = count_number(av, flag);
	if (!(stack = (int *)ft_memalloc(sizeof(int) * count)))
		return (0);
	stack = write_stack(count, stack, av, flag);
	if (check_repeat_number(stack, count))
	{
		free(stack);
		exit_error();
	}
	return (stack);
}
