#include "push_swap.h"

void simple_alg(t_head *head_a)
{
	t_stack *list;
	//int		size;

	if (head_a->stack == NULL)
		return ;
	list = head_a->stack;
	//size = head_a->size;
	
	/*
	size_t mid;
	mid = size / 2;
	*/
	t_stack *list_middle;
	/*while (head_a->stack->index != mid)
	{
		head_a->stack = head_a->stack->next;
	}*/
	list_middle = head_a->stack->next;
	//printf("list_mid = %zu\n", list_middle->index);
	//printf("list = %zu\n", list->index);
	if (list->index < list_middle->index && list_middle->index < list_middle->next->index)
		return ;
	else if (list->index > list_middle->index && list_middle->index < list_middle->next->index && list->index < list_middle->next->index)
		ft_printf("sa\n");
	else if (list->index > list_middle->index && list_middle->index > list_middle->next->index && list->index > list_middle->next->index)
		ft_printf("sa\n");
	else if (list->index > list_middle->index && list_middle->index < list_middle->next->index && list->index > list_middle->next->index)
		ft_printf("ra\n");
	else if (list->index < list_middle->index && list_middle->index > list_middle->next->index && list->index < list_middle->next->index)
		ft_printf("sa\n");
	else if (list->index < list_middle->index && list_middle->index > list_middle->next->index && list->index > list_middle->next->index)
		ft_printf("rra\n");
	//printf("Simple doesn't ready\n");
}