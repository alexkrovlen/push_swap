/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:48:23 by fjessi            #+#    #+#             */
/*   Updated: 2019/09/16 16:40:53 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_space(char *ch)
{
	if (*ch == ' ' || *ch == '\n' || *ch == '\t' || *ch == '\v' ||
		*ch == '\f' || *ch == '\r')
		return (1);
	return (0);
}

static int		ft_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int				ft_atoi_new(char *str)
{
	int		i;
	int		res;
	int		flag;

	flag = 1;
	res = 0;
	i = 0;
	if (ft_check(str))
		return (1);
	while (str[i] && ft_space(&str[i]))
		i++;
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		i++;
		flag = -1;
	}
	else if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * res + (str[i] - '0');
		i++;
	}
	return (res * flag);
}
