#include "push_swap.h"

void	pa_pb_instruction(t_head *to, t_head *from)
{
	t_stack	*tmp;
	t_stack	*tmp_h;

	if (from->stack == NULL)
		return ;
	tmp = from->stack;
	from->stack = from->stack->next;
	tmp_h = to->stack;
	tmp->next = tmp_h;
	to->stack = tmp;
}
