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
	while (tmp)//tmp->next
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
	while (tmp) //tmp->prev
	{
		if (tmp->index >= start && tmp->index < end)
			break;
		tmp = tmp->prev;
		count++;
	}
	//printf("tmp = %d\n", tmp->value);
	return (count);
}

static t_stack *find_max_min(t_head *head, int index_elem)
{
	t_stack *tmp;
	t_stack	*min;

	tmp = head->stack;
	min = NULL;
	while (tmp != NULL)
	{
		if (tmp->index < index_elem && min == NULL)
			min = tmp;
		else if (tmp->index < index_elem && min->index < tmp->index)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

static int	count_to_min_max_start(t_stack *head, int max_min)
{
	t_stack *tmp;
	int count;

	tmp = head;
	count = 0;
	while (tmp != NULL)
	{
		if (tmp->index == max_min)
			return (count);
		count++;
		tmp = tmp->next;
	}
	return (count);
}

static int	count_to_min_max_end(t_stack *head, int max_min)
{
	t_stack *tmp;
	int count;

	tmp = head;
	count = 0;
	while (tmp != NULL)
	{
		if (tmp->index == max_min)
			return (count);
		count++;
		tmp = tmp->prev;
	}
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

static int find_min_b(t_stack *head)
{
	t_stack *tmp;
	int min;

	tmp = head;
	min = 0;
	while (tmp != NULL)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

static int find_max_b(t_head *head)
{
	t_stack *tmp;
	int max;

	tmp = head->stack;
	max = 0;
	while (tmp != NULL)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

static void check_stack_rr_b(t_head *head_a, t_head *head_b, int count_step, int index_elem, t_stack *max_min)
{
	//printf("index_elem rr = %d\n", index_elem);
	//getchar();
	int count_step_s;
	int count_step_e;
	int count_step_max_s;
	int count_step_max_e;
	int min;
	
	if (head_b->stack == NULL)
		push_to_rr_b(head_a, head_b, count_step);
	else
	{
		if (max_min == NULL)
		{
			//push_to_rr_b(head_a, head_b, count_step);
			count_step_max_s = count_to_min_max_start(head_b->stack, find_max_b(head_b));
			count_step_max_e = count_to_min_max_end(last(head_b), find_max_b(head_b));
			if (count_step_max_s <= count_step_max_e + 1)
			{
				while (head_b->stack->index != find_max_b(head_b))
				{
					ra_rb_instruction(head_b);
					ft_printf("rb\n");
				}
			}
			else
			{
				while (head_b->stack->index != find_max_b(head_b))
				{
					rra_rrb_instruction(head_b);
					ft_printf("rrb\n");
				}
			}
			push_to_rr_b(head_a, head_b, count_step);
		}
		else
		{
			//printf("max_min rr = %d\n", max_min->index);
			count_step_s = count_to_min_max_start(head_b->stack, max_min->index);
			count_step_e = count_to_min_max_end(last(head_b), max_min->index);
			//printf("count_step_s min rr = %d\n", count_step_s);
			//printf("count_step_e min rr = %d\n", count_step_e);
			//getchar();
			min = find_min_b(head_b->stack);
			//printf("min = %d\n", min);
			//printf("index elem = %d\n", index_elem);
			if (min > index_elem)
			{
				count_step_max_s = count_to_min_max_start(head_b->stack, find_max_b(head_b));
				count_step_max_e = count_to_min_max_end(last(head_b), find_max_b(head_b));
				if (count_step_max_s <= count_step_max_e + 1)
				{
					while (head_b->stack->index != find_max_b(head_b))
					{
						ra_rb_instruction(head_b);
						ft_printf("rb\n");
					}
				}
				else
				{
					while (head_b->stack->index != find_max_b(head_b))
					{
						rra_rrb_instruction(head_b);
						ft_printf("rrb\n");
					}
				}
			}
			else
			{
				if (count_step_s <= count_step_e + 1)
				{
					while (head_b->stack->index != max_min->index)
					{
						ra_rb_instruction(head_b);
						ft_printf("rb\n");
					}
					push_to_rr_b(head_a, head_b, count_step);
				}
				else
				{
					while (head_b->stack->index != max_min->index)
					{
						rra_rrb_instruction(head_b);
						ft_printf("rrb\n");
					}
					push_to_rr_b(head_a, head_b, count_step);
				}
			}
		}
	}
}

static void check_stack_rrr_b(t_head *head_a, t_head *head_b, int count_step, int index_elem, t_stack *max_min)
{
	//printf("index_elem rrr = %d\n", index_elem);
	//getchar();
	int count_step_s;
	int count_step_e;
	int count_step_max_s;
	int count_step_max_e;
	int min;
	
	if (head_b->stack == NULL)
		push_to_rrr_b(head_a, head_b, count_step);
	else
	{
		if (max_min == NULL)
		{
			//push_to_rrr_b(head_a, head_b, count_step);
			count_step_max_s = count_to_min_max_start(head_b->stack, find_max_b(head_b));
			count_step_max_e = count_to_min_max_end(last(head_b), find_max_b(head_b));
			if (count_step_max_s <= count_step_max_e + 1)
			{
				while (head_b->stack->index != find_max_b(head_b))
				{
					ra_rb_instruction(head_b);
					ft_printf("rb\n");
				}
				
			}
			else
			{
				while (head_b->stack->index != find_max_b(head_b))
				{
					rra_rrb_instruction(head_b);
					ft_printf("rrb\n");
				}
			}
			push_to_rrr_b(head_a, head_b, count_step);
		}
		else
		{
			//printf("max_min rrr = %d\n", max_min->index);
			count_step_s = count_to_min_max_start(head_b->stack, max_min->index);
			count_step_e = count_to_min_max_end(last(head_b), max_min->index);
			//printf("count_step_s min rrr = %d\n", count_step_s);
			//printf("count_step_e min rrr = %d\n", count_step_e);
			//getchar();
			min = find_min_b(head_b->stack);
			if (min > index_elem)
			{
				count_step_max_s = count_to_min_max_start(head_b->stack, find_max_b(head_b));
				count_step_max_e = count_to_min_max_end(last(head_b), find_max_b(head_b));
				if (count_step_max_s <= count_step_max_e + 1)
				{
					while (head_b->stack->index != find_max_b(head_b))
					{
						ra_rb_instruction(head_b);
						ft_printf("rb\n");
					}
				}
				else
				{
					while (head_b->stack->index != find_max_b(head_b))
					{
						rra_rrb_instruction(head_b);
						ft_printf("rrb\n");
					}
				}
			}
			else
			{
				if (count_step_s <= count_step_e + 1)
				{
					while (head_b->stack->index != max_min->index)
					{
						ra_rb_instruction(head_b);
						ft_printf("rb\n");
					}
					push_to_rrr_b(head_a, head_b, count_step);
				}
				else
				{
					while (head_b->stack->index != max_min->index)
					{
						rra_rrb_instruction(head_b);
						ft_printf("rrb\n");
					}
					push_to_rrr_b(head_a, head_b, count_step);
				}
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
	t_stack *max_min;

	count_num = end - start;
	count_step_s = 0;
	count_step_e = 0;
	while (count_num > 0)
	{
		first_elem = head_a->stack;
		last_elem = last(head_a);
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
		{
			max_min = find_max_min(head_b, first_index);
			check_stack_rr_b(head_a, head_b, count_step_s, first_index, max_min);
		}
		else if (count_step_s <= count_step_e + 1 /*&& count_step_s > head_a->size / 2*/)
		{
			max_min = find_max_min(head_b, first_index);
			check_stack_rrr_b(head_a, head_b, count_step_s, first_index, max_min);
		}
		else if (count_step_s > count_step_e + 1 /*&& count_step_s <= head_a->size / 2*/)
		{
			max_min = find_max_min(head_b, last_index);
			check_stack_rrr_b(head_a, head_b, count_step_e, last_index, max_min);
		}
		else if (count_step_s > count_step_e + 1/* && count_step_s > head_a->size / 2*/)
		{
			max_min = find_max_min(head_b, last_index);
			check_stack_rr_b(head_a, head_b, count_step_e, last_index, max_min);
		}
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

	size = head_a->size / 5;
	size_last = head_a->size - size * 10;
	//printf ("size = %d\n", 2*size);
	//printf ("size_last = %d\n", size_last);
	one_part(head_a, head_b, 0, size); //0-44 ok
	one_part(head_a, head_b, size, 2*size);//45-89 ok
	one_part(head_a, head_b, 2*size, 3*size);//90-134 ok
	one_part(head_a, head_b, 3*size, 4*size);//135-179 ok
	one_part(head_a, head_b, 4*size, 5*size);//180-224 ok
	/*one_part(head_a, head_b, 5*size, 6*size);//225-269 ok
	one_part(head_a, head_b, 6*size, 7*size);//270-314 ok
	one_part(head_a, head_b, 7*size, 8*size);//315-359 ok
	one_part(head_a, head_b, 8*size, 9*size);//360-404 ok
	one_part(head_a, head_b, 9*size, 10*size);//405-449 ok
	one_part(head_a, head_b, 10*size, size_last + 10*size);//450-499 ok*/
	//print_two_stack(head_a, head_b);
	int count_step_max_s;
	int count_step_max_e;

	if (head_a->stack == NULL && head_b->stack->index != find_max_b(head_b))
	{
		count_step_max_s = count_to_min_max_start(head_b->stack, find_max_b(head_b));
		count_step_max_e = count_to_min_max_end(last(head_b), find_max_b(head_b));
		if (count_step_max_s <= count_step_max_e + 1)
		{
			while (head_b->stack->index != find_max_b(head_b))
			{
				ra_rb_instruction(head_b);
				ft_printf("rb\n");
			}
		}
		else
		{
			while (head_b->stack->index != find_max_b(head_b))
			{
				rra_rrb_instruction(head_b);
				ft_printf("rrb\n");
			}
		}
	}
	//print_two_stack(head_a, head_b);




	//printf("Advanced is ready\n");
}