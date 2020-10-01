#include "push_swap.h"

void	ra_rb_instruction(t_head *head)
{
	t_stack *tmp_first;
	t_stack *tmp_second;

	if (head->stack == NULL)
		return ;
	print_stack(head);
	tmp_first = head->stack;
	head->stack = head->stack->next;
	tmp_second = head->stack;
	while (tmp_second->next != NULL)
		tmp_second = tmp_second->next;
	tmp_second->next = tmp_first;
	tmp_first->next = NULL;
	printf("!!!!!!\n");
	print_stack(head);
	printf("trenirovka_ra_rb_instruction!!!\n");
}

void	rr_instruction(t_head *head_a, t_head *head_b)
{
	ra_rb_instruction(head_a);
	ra_rb_instruction(head_b);
}