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
	//printf("??????\n");
	while (start < end)
	{
		//printf("array[start] = %d\n", array[start]);
		//	printf("array[end] = %d\n", array[end]);
		if (array[start] <= array[end])
		{/*
			printf("%%\n");
			printf("i = %d\n", i);
			printf("start = %d\n", start);
			printf("end = %d\n", end);
			printf("temp = %d\n", temp);
			printf("array[i] = %d\n", array[i]);
			*/
			i++;
			temp = array[i];
			array[i] = array[start];
			array[start] = temp;
			/*printf("i = %d\n", i);
			printf("start = %d\n", start);
			printf("end = %d\n", end);
			printf("temp = %d\n", temp);
			printf("array[i] = %d\n", array[i]);
			printf("array[start] = %d\n", array[start]);*/
		}
		start++;
	}
	/*printf("posle cikla\n");
	printf("i = %d\n", i);
			printf("start = %d\n", start);
			printf("end = %d\n", end);
			printf("temp = %d\n", temp);
			printf("array[i + 1] = %d\n", array[i + 1]);
			printf("array[end] = %d\n", array[end]);
		*/
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	/*printf("i = %d\n", i);
			printf("start = %d\n", start);
			printf("end = %d\n", end);
			printf("temp = %d\n", temp);
			printf("array[i + 1] = %d\n", array[i + 1]);
			printf("array[end] = %d\n", array[end]);
		printf("return = %d\n", i + 1);	*/
	return i + 1;
}

int		*sort_massiv(int *stack, int start, int end)
{
	int q;

	/*printf("!!!!!!!!\n");
	printf("stack = ");
	for (int i = 0; i <= end; i++)
		printf("%d ", stack[i]);
	printf("\nstart = %d\n", start);
	printf("end = %d\n", end);*/
	if (start < end)
	{
		q = partition(stack, start, end);//printf("q = %d\n", q);
		sort_massiv(stack, start, q - 1);
		sort_massiv(stack, q + 1, end);
	}
	return(stack);
}