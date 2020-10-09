#include "push_swap.h"

static t_stack *last(t_head *head)
{
	t_stack *tmp;

	tmp = head->stack;
	while (tmp->next)
		tmp = tmp->next;
	return(tmp);
}

static int get_first_index(t_stack *head, int count)
{
	t_stack *tmp;
	int 	index;

	tmp = head;
	while (count > 0)
	{
		tmp = tmp->next;
		count--;
	}
	index = tmp->index;
	return (index);
}

static int get_last_index(t_stack *head, int count)
{
	t_stack *tmp;
	int 	index;

	tmp = head;
	while (count > 0)
	{
		tmp = tmp->prev;
		count--;
	}
	index = tmp->index;
	return (index);
}

static int check_count_step_next(t_stack *head, int start, int end)
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

static int check_count_step_prev(t_stack *head, int start, int end)
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

static void check_stack_rrr_b(t_head *head_a, t_head *head_b, int count_step, int index_elem)
{
	//printf("index_elem rrr= %d\n", index_elem);
	//getchar();
	int dif_first_elem;
	int dif_last_elem;
	int dif_first;
	int dif_last;
	int count;

	
	if (head_b->stack == NULL)
		push_to_rrr_b(head_a, head_b, count_step);
	else
	{
		dif_first_elem = (head_b->stack)->index - index_elem;
		dif_last_elem = last(head_b)->index - index_elem;
		//printf("dif_first_elem = %d\n", dif_first_elem);
		//printf("dif_last_elem = %d\n", dif_last_elem);
		//getchar();
		if (dif_first_elem < 0)
			dif_first = dif_first_elem * (-1);
		else
			dif_first = dif_first_elem;
		if (dif_last_elem < 0)
			dif_last = dif_last_elem * (-1);
		else
			dif_last = dif_last_elem;
		if (dif_first <= dif_last)
		{
			if (dif_first_elem > 0)
			{
				count = 0;
				while (head_b->stack && head_b->stack->index > index_elem)
				{
					ra_rb_instruction(head_b);
					ft_printf("rb\n");
					count++;
				}
				push_to_rrr_b(head_a, head_b, count_step);
				while (count > 0)
				{
					rra_rrb_instruction(head_b);
					ft_printf("rrb\n");
					count--;
				}
			}
			else
			{
				push_to_rrr_b(head_a, head_b, count_step);
			}
		}
		else if (dif_first > dif_last)
		{
			if (dif_last_elem < 0)
			{
				count = 0;
				while (head_b->stack && last(head_b)->index < index_elem)
				{
					rra_rrb_instruction(head_b);
					ft_printf("rrb\n");
					count++;
				}
				push_to_rrr_b(head_a, head_b, count_step);
				while (count + 1 > 0)
				{
					ra_rb_instruction(head_b);
					ft_printf("rb\n");
					count--;
				}
			}
			else
			{
				push_to_rrr_b(head_a, head_b, count_step);
				ra_rb_instruction(head_b);
				ft_printf("rb\n");
			}
		}
	}
}

static void check_stack_rr_b(t_head *head_a, t_head *head_b, int count_step, int index_elem)
{
	//printf("index_elem rr = %d\n", index_elem);
	//getchar();
	int dif_first_elem;
	int dif_last_elem;
	int dif_first;
	int dif_last;
	int count;
	
	if (head_b->stack == NULL)
		push_to_rr_b(head_a, head_b, count_step);
	else
	{
		dif_first_elem = (head_b->stack)->index - index_elem;
		dif_last_elem = last(head_b)->index - index_elem;
		//printf("dif_first_elem = %d\n", dif_first_elem);
		//printf("dif_last_elem = %d\n", dif_last_elem);
		//getchar();
		if (dif_first_elem < 0)
			dif_first = dif_first_elem * (-1);
		else
			dif_first = dif_first_elem;
		if (dif_last_elem < 0)
			dif_last = dif_last_elem * (-1);
		else
			dif_last = dif_last_elem;
		if (dif_first <= dif_last)//сделать не на разницу а на середину отрезка(size)
		{
			if (dif_first_elem > 0)
			{
				count = 0;
				if (head_b->stack && head_b->stack->index > index_elem && head_b->stack->next == NULL)
					count++;
				else
				{
					while (head_b->stack && head_b->stack->index > index_elem)
					{
						ra_rb_instruction(head_b);
						ft_printf("rb\n");
						count++;
					}
				}
				push_to_rr_b(head_a, head_b, count_step);
				while (count > 0)
				{
					rra_rrb_instruction(head_b);
					ft_printf("rrb\n");
					count--;
				}
			}
			else
				push_to_rr_b(head_a, head_b, count_step);
		}
		else if (dif_first > dif_last)
		{
			if (dif_last_elem < 0)
			{
				count = 0;
				while (head_b->stack && last(head_b)->index < index_elem)
				{
					rra_rrb_instruction(head_b);
					ft_printf("rrb\n");
					count++;
				}
				push_to_rr_b(head_a, head_b, count_step);
				while (count + 1 > 0)
				{
					ra_rb_instruction(head_b);
					ft_printf("rb\n");
					count--;
				}
			}
			else
			{
				push_to_rr_b(head_a, head_b, count_step);
				ra_rb_instruction(head_b);
				ft_printf("rb\n");
			}
		}
	}
}

static void one_part(t_head *head_a, t_head *head_b, int start, int end)
{
	t_stack *last_elem;
	t_stack *first_elem;
	int count_num;
	int count_step_s;
	int count_step_e;
	int first_index;
	int last_index;

	count_num = end - start;
	count_step_s = 0;
	count_step_e = 0;
	//if(head_b->stack != NULL)
	//	return ;
	
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
		printf("start = %d\n", start);
		printf("end = %d\n", end);
		getchar();*/
		count_step_s = check_count_step_next(first_elem, start, end);
		count_step_e = check_count_step_prev(last_elem, start, end);
		first_index = get_first_index(first_elem, count_step_s);
		last_index = get_last_index(last_elem, count_step_e);
		//printf("step start = %d\n", count_step_s);
		//printf("step end= %d\n", count_step_e);
		//printf("first_index = %d\n", first_index);
		//printf("last_index = %d\n", last_index);
		//getchar();
		//printf("size / 2 = %d\n", head_a->size/2);
		//getchar();
		if (count_step_s <= count_step_e + 1/* && count_step_s <= head_a->size / 2*/)
			check_stack_rr_b(head_a, head_b, count_step_s, first_index);
		else if (count_step_s <= count_step_e + 1 /*&& count_step_s > head_a->size / 2*/)
			check_stack_rrr_b(head_a, head_b, count_step_s, first_index);
		else if (count_step_s > count_step_e + 1 /*&& count_step_s <= head_a->size / 2*/)
			check_stack_rrr_b(head_a, head_b, count_step_e, last_index);
		else if (count_step_s > count_step_e + 1/* && count_step_s > head_a->size / 2*/)
			check_stack_rr_b(head_a, head_b, count_step_e, last_index);	
		count_num--;
		//print_two_stack(head_a, head_b);
		//getchar();
	}
	//print_two_stack(head_a, head_b);
	//getchar();
}

void advanced_alg(t_head *head_a)
{
	t_head	*head_b;

	if (head_a == NULL)
		return ;
	if (!(head_b = (t_head *)ft_memalloc(sizeof(t_head))))
		exit_error();
	
	int size;
	int size_last;

	size = head_a->size / 11;
	size_last = head_a->size - size * 10;
	//printf ("size = %d\n", 2*size);
	//printf ("size_last = %d\n", size_last);
	one_part(head_a, head_b, 0, size); //0-44 ok
	one_part(head_a, head_b, size, 2*size);//45-89 ok
	one_part(head_a, head_b, 2*size, 3*size);//90-134 ok
	one_part(head_a, head_b, 3*size, 4*size);//135-179 ok
	one_part(head_a, head_b, 4*size, 5*size);//180-224 ok
	one_part(head_a, head_b, 5*size, 6*size);//225-269 ok
	one_part(head_a, head_b, 6*size, 7*size);//270-314 ok
	one_part(head_a, head_b, 7*size, 8*size);//315-359 ok
	one_part(head_a, head_b, 8*size, 9*size);//360-404 ok
	one_part(head_a, head_b, 9*size, 10*size);//405-449 ok
	one_part(head_a, head_b, 10*size, size_last + 10*size);//450-499 ok
	//print_two_stack(head_a, head_b);
	//printf("Advanced is ready\n");
}