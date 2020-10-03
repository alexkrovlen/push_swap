#include "push_swap.h"
/*
static void		midle_swap(t_head *head_a, t_head *head_b)
{
	size_t	size;

	size = head_a->size / 8;
		if (head_b->stack->index > head_b->stack->next->index)
		{
			sa_sb_instruction(head_b);
			ft_printf("sb\n");
		}
		else
		{
			ra_rb_instruction(head_b);
			ft_printf("rb\n");
		}
}*/

static void		midle_sort(t_head *head_a, t_head *head_b)
{
	size_t	size;
	size_t	midl;

	size = head_a->size / 8;
	midl = size / 2;printf("midl = %zu\n", midl);
	while (head_b->stack)
	{
		if (head_b->stack->index > head_b->stack->next->index)
		{
			sa_sb_instruction(head_b);
			ft_printf("sb\n");
		}
		else
		{
			ra_rb_instruction(head_b);
			ft_printf("rb\n");
		}
		/*if (head_b->stack->index < midl)
			midle_swap(head_a, head_b);
		size--;*/
		print_two_stack(head_a, head_b);
		getchar();
	}
}

static void		midle_eighth(t_head *head_a, t_head *head_b)
{
	size_t	size;

	size = head_a->size / 4;
	//printf("size = %zu\n", size);
	while (size > 0)
	{
		if (head_b->stack->index > head_a->size / 8)
		{
			pa_pb_instruction(head_a, head_b);
			ft_printf("pa\n");
		}
		else
		{
			ra_rb_instruction(head_b);
			ft_printf("rb\n");
		}
		size--;
	}
}

static void		midle_fourth(t_head *head_a, t_head *head_b)
{
	size_t	size;

	size = head_a->size / 2;
	//printf("size = %zu\n", size);
	while (size > 0)
	{
		if (head_b->stack->index > head_a->size / 4)
		{
			pa_pb_instruction(head_a, head_b);
			ft_printf("pa\n");
		}
		else
		{
			ra_rb_instruction(head_b);
			ft_printf("rb\n");
		}
		size--;
	}
}

static void		middle_half(t_head *head_a, t_head *head_b)
{
	size_t	size;

	size = head_a->size;
	while (size > 0)
	{
		if (head_a->stack->index < head_a->size / 2)
		{
			pa_pb_instruction(head_b, head_a);
			ft_printf("pb\n");
		}
		else
		{
			ra_rb_instruction(head_a);
			ft_printf("ra\n");
		}
		size--;
	}
	//head_b->size = head_a->size / 2;
	//head_a->size = head_a->size - head_b->size;
}

void middle_alg(t_head *head_a)
{
	t_head	*head_b;

	if (head_a == NULL)
		return ;
	if (!(head_b = (t_head *)ft_memalloc(sizeof(t_head))))
		exit_error();
	middle_half(head_a, head_b);
	print_two_stack(head_a, head_b);
	getchar();

	midle_fourth(head_a, head_b);
	print_two_stack(head_a, head_b);
	getchar();

	midle_eighth(head_a, head_b);
	print_two_stack(head_a, head_b);
	getchar();

	midle_sort(head_a, head_b);
	print_two_stack(head_a, head_b);
	getchar();
	//printf("s_a = %zu\n", head_a->size);
	//printf("s_b = %zu\n", head_b->size);
	//print_two_stack(head_a, head_b);
	printf("Middle doesn't ready\n");
}
/*
printf("i = %zu\n", i);
print_stack(head_a);
printf("\n");
print_stack(head_b);
printf("\n");
getchar ();
*/