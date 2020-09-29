/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:45:28 by fjessi            #+#    #+#             */
/*   Updated: 2020/09/16 15:45:31 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		get_index(t_head *head_a, int *str, int count)
{
	int		i;
	t_stack	*list;
	t_stack	*temp;

	i = 0;
	list = head_a->stack;
	temp = list;
	while (i < count)
	{
		while (list)
		{
			if (str[i] == list->value)
			{
				//printf("value = %d\n", list->value);
				list->index = i;
				//printf("index = %zu\n", list->index);
				break ;
			}
			else
				list = list->next;
		}
		list = temp;
		i++;
	}
	free(temp);
}
