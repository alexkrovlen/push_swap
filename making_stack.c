/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_making_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:45:28 by fjessi            #+#    #+#             */
/*   Updated: 2020/09/16 15:45:31 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static t_stack	*get_new_list(int val, t_stack *head)
{
	t_stack *list;

    list = (t_stack *)ft_memalloc(sizeof(t_stack));
    list->value = val;
	list->index = 0;
	list->next = NULL;
    head->next = list;
    return (list);
}

static t_head	*do_it(int *str, int count)
{
	t_head	*head;
	int		i;
	t_stack	*list;
	t_stack *tmp;

	i = 0;
	list = NULL;
	head = (t_head *)ft_memalloc(sizeof(t_head));
	list = (t_stack *)ft_memalloc(sizeof(t_stack));
	tmp = list;
    list->value = str[i++];
	list->index = 0;
	list->next = NULL;
	head->size = count;
	while (i < count)
	{
		list = get_new_list(str[i], list);
		//printf("value = %d\ni = %d\n", list->value, i);
		i++;
	}
	head->stack = tmp;
	return (head);
}

t_head			*making_stack(int ac, char **av)
{
	int		*stack;
	int		count;
	t_head	*head_a;

	stack = validation(ac, av); //yе отсортированный массив
	count = count_number(av); //кол-во цифр
	head_a = do_it(stack, count); //массив записали в структуру
	//printf("count = %d\n", count);
	//printf("head = %d\n", head_a->stack->value);
	sort_massiv(stack, 0, count - 1); //сортируем массив
	/*for (int i = 0; i < count; i++)
		printf("%d ", stack[i]);*/
	get_index(head_a, stack, count);
	//printf("ind = %zu\n", head_a->stack->index);
	printf("head = %d\n", head_a->stack->value);
	return (head_a);
}
