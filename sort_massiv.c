/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_massiv.c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:45:28 by fjessi            #+#    #+#             */
/*   Updated: 2020/09/24 16:45:31 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int partition(int *array, int start, int end)
{
	int i;
	int temp;

	i = start - 1;
	temp = 0;
	while (start < end)
	{
		if (array[start] <= array[end])
		{
			i++;
			temp = array[i];
			array[i] = array[start];
			array[start] = temp;
		}
		start++;
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	return i + 1;
}

int		*sort_massiv(int *stack, int start, int end)
{
	int q;

	if (start < end)
	{
		q = partition(stack, start, end);
		sort_massiv(stack, start, q - 1);
		sort_massiv(stack, q + 1, end);
	}
	return(stack);
}