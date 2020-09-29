/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <pelease@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 01:13:29 by pelease           #+#    #+#             */
/*   Updated: 2020/06/19 01:46:21 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			array_round(int *numbers, int *left, int *right, int pivot)
{
	while (*left < *right)
	{
		while ((numbers[*right] >= pivot) && (*left < *right))
			(*right)--;
		if (*left != *right)
		{
			numbers[*left] = numbers[*right];
			(*left)++;
		}
		while ((numbers[*left] <= pivot) && (*left < *right))
			(*left)++;
		if (*left != *right)
		{
			numbers[*right] = numbers[*left];
			(*right)--;
		}
	}
}

void				array_sort(int *numbers, int left, int right)
{
	int				pivot;
	int				l_hold;
	int				r_hold;

	pivot = numbers[left];
	l_hold = left;
	r_hold = right;
	array_round(numbers, &left, &right, pivot);
	numbers[right] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		array_sort(numbers, left, pivot - 1);
	if (right > pivot)
		array_sort(numbers, pivot + 1, right);
}
