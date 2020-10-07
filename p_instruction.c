#include "push_swap.h"

void	pa_pb_instruction(t_head *to, t_head *from)
{
	t_stack	*tmp;
	t_stack	*tmp_h;

	if (from->stack == NULL)
		return ;
	tmp = from->stack;
	from->stack = from->stack->next;
	if (from->stack)
		from->stack->prev = NULL;
	tmp_h = to->stack;
	tmp->next = tmp_h;
	to->stack = tmp;
	to->stack->prev = NULL;
	if (to->stack->next)
		to->stack->next->prev = to->stack->next;
	//print_two_stack(to, from);
}
