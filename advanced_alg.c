#include "push_swap.h"

static t_stack *last(t_head *head)
{
	t_stack *tmp;

	tmp = head->stack;
	while (tmp->next)
		tmp = tmp->next;
	return(tmp);
}

static int check_count_step_next(t_stack *head, size_t start, size_t end)
{
	t_stack *tmp;
	int count;
	
	tmp = head;
	count = 0;
	while (tmp->next)
	{
		if (tmp->index >= start && tmp->index < end)
			break;
		tmp = tmp->next;
		count++;
	}
	//printf("tmp = %d\n", tmp->value);
	return (count);
}

static int check_count_step_prev(t_stack *head, size_t start, size_t end)
{
	t_stack *tmp;
	int count;
	
	tmp = head;
	count = 0;
	while (tmp->prev)
	{
		if (tmp->index >= start && tmp->index < end)
			break;
		tmp = tmp->prev;
		count++;
	}
	//printf("tmp = %d\n", tmp->value);
	return (count);
}

static void push_to_rr_b(t_head *head_a, t_head *head_b, int count_step)
{
	while (count_step > 0)
	{
		ra_rb_instruction(head_a);
		ft_printf("ra\n");
		count_step--;
	}
	pa_pb_instruction(head_b, head_a);
	ft_printf("pb\n");
	head_a->size--;
}

static void push_to_rrr_b(t_head *head_a, t_head *head_b, int count_step)
{
	while (count_step > 0)
	{
		rra_rrb_instruction(head_a);
		ft_printf("rra\n");
		count_step--;
	}
	rra_rrb_instruction(head_a);
	ft_printf("rra\n");
	pa_pb_instruction(head_b, head_a);
	ft_printf("pb\n");
	head_a->size--;
}

static void one_part(t_head *head_a, t_head *head_b, size_t start, size_t end)
{
	t_stack *last_elem;
	t_stack *first_elem;
	int count_num;
	size_t count_step_s;
	size_t count_step_e;

	count_num = end;
	count_step_s = 0;
	count_step_e = 0;
	if(head_b->stack != NULL)
		return ;
	
	/*
	printf("!!!!!\n");
	
	printf("head = %d\n", head_a->stack->value);
	*/
	while (count_num > 0)
	{
		first_elem = head_a->stack;
		last_elem = last(head_a);
		/*printf("first = %d\n", first_elem->value);
		printf("last = %d\n", last_elem->value);
		getchar();
		printf("start = %zu\n", start);
		printf("end = %zu\n", end);
		getchar();*/
		count_step_s = check_count_step_next(first_elem, start, end);
		count_step_e = check_count_step_prev(last_elem, start, end);
		printf("step start = %zu\n", count_step_s);
		printf("step end= %zu\n", count_step_e);
		getchar();
		printf("size / 2 = %zu\n", head_a->size/2);
		getchar();
		if (count_step_s <= count_step_e + 1 && count_step_s <= head_a->size / 2)
			push_to_rr_b(head_a, head_b, count_step_s);
		else if (count_step_s <= count_step_e + 1 && count_step_s > head_a->size / 2)
			push_to_rrr_b(head_a, head_b, count_step_s);
		else if (count_step_s > count_step_e + 1 && count_step_s <= head_a->size / 2)
			push_to_rrr_b(head_a, head_b, count_step_e);
		else if (count_step_s > count_step_e + 1 && count_step_s > head_a->size / 2)
			push_to_rr_b(head_a, head_b, count_step_e);	
		count_num--;
		print_two_stack(head_a, head_b);
		getchar();
	}
	print_two_stack(head_a, head_b);
	//getchar();
}

void advanced_alg(t_head *head_a)
{
	t_head	*head_b;

	if (head_a == NULL)
		return ;
	if (!(head_b = (t_head *)ft_memalloc(sizeof(t_head))))
		exit_error();
	
	size_t size;
	size_t size_last;

	size = head_a->size / 11;
	size_last = head_a->size - size * 10;
	//printf ("size = %zu\n", size);
	//printf ("size_last = %zu\n", size_last);
	one_part(head_a, head_b, 0, size); //0-44 //начать с того что в стэк б на правильное мест0
	//one_part(head_a, head_b, size, 2*size);//45-89
	//one_part(head_a, head_b, 2*size, 3*size);//90-134
	//one_part(head_a, head_b, 3*size, 4*size);//135-179
	//one_part(head_a, head_b, 4*size, 5*size);//180-224
	//one_part(head_a, head_b, 5*size, 6*size);//225-269
	//one_part(head_a, head_b, 6*size, 7*size);//270-314
	//one_part(head_a, head_b, 7*size, 8*size);//315-359
	//one_part(head_a, head_b, 8*size, 9*size);//360-404
	//one_part(head_a, head_b, 9*size, 10*size);//405-449
	//one_part(head_a, head_b, 10*size, size_last);//450-499
	printf("Advanced doesn't ready\n");
}