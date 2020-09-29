/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:45:28 by fjessi            #+#    #+#             */
/*   Updated: 2020/02/26 15:45:31 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define INT_MIN -2147483648
#define INT_MAX 2147483647

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
		if ((str[i] < '0' || str[i] > '9' || ft_space(&str[i])) &&\
			str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

long int	ft_atoi_new(char *str)
{
	int			i;
	long int	res;
	int			flag;

	flag = 1;
	res = 0;
	i = 0;//printf("str2 = %s\n", str);
	if (ft_check(str))
		exit_error();
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

/*static int		check_number(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi_new(av[i]) >= INT_MIN && ft_atoi_new(av[i]) <= INT_MAX)
			i++;
		else
			exit_error();
	}
	return (0);
}*/

static int		check_number(int ac, char **av)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	j = 0;
	while (i < ac)
	{
		str = ft_strsplit(&av[i][j], ' '); //printf("str1 = %s\n", *str);
		while (*str)
		{
			if (ft_atoi_new(*str) >= INT_MIN && ft_atoi_new(*str) <= INT_MAX)
				str++;
			else
				exit_error();
		}
		i++;
	}
	return (0);
}

/*static int		check_repeat(char **av)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			k = j + 1;
			while (av[i][k])
			{
				printf("av[j] = %c  av[k] = %c\n", av[i][j], av[i][k]);
				if (av[i][j] == av[i][k] && av[i][j] != ' ')
					exit_error();
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}*/
// ниже херовая версия чекера репит
/*static int		check_repeat(int ac, char **av) //в буфер записать нельзя, та как мы не знаем количество паданных элемнтов, поэтому записать все в стэк аи првоерить на повторяющиеся
{
	char	**str;
	int		i;
	int		l;
	int		m;
	int		k;

	l = 1;
	m = 0;
	printf("?\n");
	while (l < ac)
	{
		str = ft_strsplit(&av[l][m], ' ');
		l++;
	}
	//printf("str3 = %s\n", *str);
	printf("!\n");
	i = 0;
	k = i + 1;
	while (str[i] != '\0')
	{printf("str3 = %s\n", str[i]);printf("i3 = %d\n", i);
		while (str[i] && str[k])
		{printf("%%\n");
			printf("str[i] = %s  str[k] = %s\n", str[i], str[k]);
			if (str[i] == str[k])
				exit_error();
			k++;
		}
		i++;
	}
	return (0);
}*/

int				*validation(int ac, char **av)
{
	int		*stack;

	if (ac >= 2)
	{
		if (check_number(ac, av))
			exit_error();
	}
	else
		exit_error();//return(1);
	stack = check_repeat(av);
	return (stack);
}
