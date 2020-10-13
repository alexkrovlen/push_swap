/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_making_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:45:28 by fjessi            #+#    #+#             */
/*   Updated: 2020/10/02 17:32:43 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_new_list(int val, t_stack *head)
{
	t_stack *list;

	if (!(list = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	list->value = val;
	list->index = 0;
	list->next = NULL;
	head->next = list;
	return (list);
}

static t_head	*do_it(int *str, int count, t_head *head)
{
	int		i;
	t_stack	*list;
	t_stack *tmp;
	t_stack *tmp_list;

	i = 0;
	if (!(list = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	tmp = list;
	list->value = str[i++];
	list->index = 0;
	list->prev = NULL;
	head->size = count;
	while (i < count)
	{
		tmp_list = list;
		list->next = get_new_list(str[i], list);
		list = list->next;
		list->prev = tmp_list;
		i++;
	}
	head->stack = tmp;
	return (head);
}

static int		check_flag(char **av)
{
	if (av[1][0] == '-' && av[1][1] == 'v' && !av[1][2])
		return (1);
	return (0);
}

t_head			*making_stack(int ac, char **av)
{
	int		*stack;
	int		count;
	t_head	*head_a;

	head_a = (t_head *)ft_memalloc(sizeof(t_head));
	head_a->flag = check_flag(av);
	stack = validation(ac, av, head_a->flag);
	count = count_number(av, head_a->flag);
	head_a = do_it(stack, count, head_a);
	sort_massiv(stack, 0, count - 1);
	get_index(head_a, stack, count);
	free(stack);
	return (head_a);
}

t_head			*making_b(void)
{
	t_head	*head;

	if (!(head = (t_head *)ft_memalloc(sizeof(t_head))))
		exit_error();
	head->stack = NULL;
	head->flag = 0;
	head->size = 0;
	return (head);
}
