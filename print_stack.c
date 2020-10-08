#include "push_swap.h"

void	print_stack_index(t_head *a)
{
	t_stack	*b;

	b = a->stack;
	while (b)
	{
		printf("%3d----%3d\n", b->value, b->index);
		//getchar();
		b = b->next;
	}
	//printf("%d\n", b->stack->value);
	//getchar();
}

void	print_stack(t_head *a)
{
	t_stack	*b;

	b = a->stack;
	while (b)
	{
		printf("%d\n", b->value);
		//getchar();
		b = b->next;
	}
	//printf("%d\n", b->stack->value);
	//getchar();
}

void	print_two_stack(t_head *a, t_head *b)
{
	t_stack	*aa;
	t_stack	*bb;

	aa = a->stack;
	bb = b->stack;
	printf("a    b\n");
	printf("_______\n");
	while (aa || bb)
	{
		if (aa && bb)
		{
			printf("%d   %d\n", aa->value, bb->value);
			aa = aa->next;
			bb = bb->next;
		}
		else if (aa && bb == NULL)
		{
			printf("%d   #\n", aa->value);
			aa = aa->next;
			//bb = bb->next;
		}
		else if (aa == NULL && bb)
		{
			printf("#   %d\n", bb->value);
			//aa = aa->next;
			bb = bb->next;
		}
	}
}