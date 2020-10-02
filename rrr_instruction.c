#include "push_swap.h"

void	rra_rrb_instruction(t_head *head)
{
	t_stack		*tmp_first;
	t_stack		*tmp_last;
	t_stack		*tmp;

	if (head->stack == NULL)
		return ;
	if (head->stack->next == NULL)
		return ;
	tmp_first = head->stack;
	while (head->stack->next != NULL)
	{
		tmp = head->stack;
		head->stack = head->stack->next;
	}
	tmp_last = head->stack;
	tmp_last->next = tmp_first;
	tmp->next = NULL;
	head->stack = tmp_last;
}

void	rrr_instruction(t_head *head_a, t_head *head_b)
{
	rra_rrb_instruction(head_a);
	rra_rrb_instruction(head_b);
}
