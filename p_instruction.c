#include "push_swap.h"

void	pa_pb_instruction(t_head *to, t_head *from)
{
	t_stack	*tmp;

	
	if (from->stack == NULL)
		return ;
	printf("TO\n");
	print_stack(to);
	printf("FROM\n");
	print_stack(from);
	tmp = from->stack;
	from->stack = from->stack->next;
	to->stack = tmp;
	to->stack->next = NULL;
	printf("!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("TO\n");
	print_stack(to);
	printf("FROM\n");
	print_stack(from);
	printf("trenirovka_pb_instruction!!!\n");
}
